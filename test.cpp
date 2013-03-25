#include "engine.h"

bool GraphicsEngine::init()
{
	TextureMgr::get().load("engine","resources/images/engine.tga");
	TextureMgr::get().load("explosion","resources/images/explosion.tga");
	TextureMgr::get().load("engine64","resources/images/engine64.tga");
	TextureMgr::get().load("missile","resources/images/missile.tga");
	TextureMgr::get().load("star","resources/images/star.tga");
	TextureMgr::get().load("fire","resources/images/fire.tga");
	TextureMgr::get().load("button","resources/images/button.tga");
	TextureMgr::get().load("white","resources/images/tile.tga");
	TextureMgr::get().load("radar","resources/images/radar.tga");
	TextureMgr::get().load("radargrid","resources/images/radargrid.tga");
	TextureMgr::get().load("shipoutline","resources/images/shipoutline.tga");
	TextureMgr::get().load("radaricon","resources/images/radaricon.tga");
	TextureMgr::get().load("radariconfriendly","resources/images/radariconfriendly.tga");
	TextureMgr::get().load("radariconweapon","resources/images/radariconweapon.tga");
	TextureMgr::get().load("radariconcurtarget","resources/images/radariconcurtarget.tga");
	TextureMgr::get().load("weaponpanel","resources/images/textdisplay.tga");
	TextureMgr::get().load("crosshair","resources/images/crosshair.tga");
	TextureMgr::get().load("beam","resources/images/beam.tga");
	ShaderMgr::get().load("perpixelv","resources/shaders/pointlight.vert",GL_VERTEX_SHADER);
	ShaderMgr::get().load("perpixelf","resources/shaders/pointlight.frag",GL_FRAGMENT_SHADER);
	ShaderMgr::get().linkProgram("perpixel","perpixelv","perpixelf");

	//ShaderMgr::get().load("volumelinev","resources/shaders/shader.vert",GL_VERTEX_SHADER);
	//ShaderMgr::get().linkProgram("volumeline","volumelinev","");


/*	ModelMgr::get().load(new C3ds("missile","resources/models/rocket.3ds","perpixel",1.0f));

	ModelMgr::get().load(new C3ds("soyuz","resources/models/soyuztma-3.3ds","perpixel",1.0f));
	ModelMgr::get().load(new C3ds("ship","resources/models/ship.3ds","perpixel",1.0f));
	ModelMgr::get().load(new C3ds("space","resources/models/sky.3ds","",1000000.0f));
	ModelMgr::get().load(new C3ds("asteroid","resources/models/asteroid.3ds","perpixel",1.0f));
	//ObjectMgr::get().add(new GravityWell("planet","cube",(Vector){10000.0f,100.0f,0.0f},(Vector){0.0f,0.0f,0.0f}, 20000000.0f,1.0f));

	FactionMgr::get().add(new Faction("Evildoers","Those who do evil"));
	FactionMgr::get().add(new Faction("default","Good guys?"));


	for(int i=0;i<10;i++)
	{
		std::ostringstream shipName;
		shipName <<"ship-e-"<<rand();
		ObjectMgr::get().add(new Ship(shipName.str(),"evildoers","soyuz",(Vector){(double)(rand()%1000-500)+10000.0f,(double)(rand()%1000-500),(double)(rand()%1000-500)},(Vector){(double)(rand()%200-100),(double)(rand()%200-100),(double)(rand()%200-100)},20000.0f,5.0f));
	}


	//ObjectMgr::get().add(new SpaceObject("Teh badass","evildoers","cube",(Vector){2000.0f,2000.0f,2000.0f},(Vector){0.0f,0.0f,0.0f},400000.0f,500.0f));


	for(int i=0;i<10;i++)
	{
		std::ostringstream shipName;
		shipName <<"ship-g-"<<rand();
		ObjectMgr::get().add(new Ship(shipName.str(),"default","soyuz",(Vector){(double)(rand()%1000-500),(double)(rand()%1000-500),(double)(rand()%1000-500)},(Vector){(double)(rand()%1000-500)/100.0f,(double)(rand()%1000-500)/100.0f,(double)(rand()%1000-500)/100.0f},20000.0f,5.0f));
	}




	ObjectMgr::get().add(new Player("player","default","ship",(Vector){0.0f,0.0f,0.0f},(Vector){0.0f,0.0f,0.0f}, Camera::get().getQuaternion(), 15000.0f,5.0f));


	//Normally 300000, 1e20
	ObjectMgr::get().add(new GravityWell("asteroid","asteroid",(Vector){300000.0f,0.0f,0.0f},(Vector){0.0f,0.0f,0.0f}, 1e20,200000));

	*/

	Scenario defaultScenario("default", "resources/scenarios/default.gl2");


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT,(const GLfloat[4]){0.0f, 0.0f, 0.0f, 1.0f});
	glLightfv(GL_LIGHT0, GL_DIFFUSE, (const GLfloat[4]){ 0.5f, 0.5f, 0.5f, 1.0f });
	glLightfv(GL_LIGHT0, GL_SPECULAR, (const GLfloat[4]){ 0.5f, 0.5f, 0.5f, 0.1f });
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, (const GLfloat[4]){0.0f, 0.0f, 0.0f, 1.0f});
	return true;
}

void GraphicsEngine::main()
{
	keyInterval=0;
	screenshotKeyInterval=0;
	done=false;
	showTerminal = false;
	renderPlayer = false;

	glMatrixMode(GL_MODELVIEW);

	bool renderCycle = true;
	numSamples = 0;
	curSample = 0;
	while(!done){
		GlobalTime::get().startFrame();

		if(curSample == numSamples)
		{
			renderCycle = true;
			curSample = 0;
		} else {
			renderCycle = false;
			curSample++;
		}
		SDL_PollEvent(&event);
		keys=SDL_GetKeyState(NULL);

		if(renderCycle)
		{
			glMatrixMode(GL_MODELVIEW);
			// glEnable(GL_LIGHTING);
			glLoadIdentity();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glClearColor(0.0f,0.0f,0.0f,1.0f);
		}

		srand(SDL_GetTicks());


		ParticleMgr::get().handle();
		ObjectMgr::get().handle();

		ObjectMgr::get().positionPlayer();




		if(renderCycle)
		{
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glLoadIdentity();
			Camera::get().setPerspective();
			ModelMgr::get().render("space");
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//std::cout<<(pos+up*0.02f+look*0.07f).x<<" "<<(pos+up*0.02f+look*0.07f).y<<" "<<(pos+up*0.02f+look*0.07f).z<<std::endl;
			ObjectMgr::get().render();

			ParticleMgr::get().render();


			//handle player (takes care of z-sorting with a transparent glass cockpit)
			ObjectMgr::get().renderPlayer(renderPlayer);

			glLightfv(GL_LIGHT0, GL_POSITION, (const GLfloat[3]){100000.0f,-100000.0f,-100000.0f});
		}

		Player *p = ((Player*)ObjectMgr::get().find("player"));

		if(renderCycle)
		{
			if(p)p->renderHUD();

			glLoadIdentity();
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();

			/*
			glDisable(GL_LIGHTING);


			glLoadIdentity();

			int mx,my,b;
			b=0;
			SDL_GetMouseState(&mx,&my);

			Gui::get().render();
			Gui::get().handle(mx,my, SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1));
		*/
			glDisable(GL_LIGHTING);



			glColor4f(1.0f,1.0f,1.0f,1.0f);

			if(term->getDebugState())
			{
				glRasterPos2f(0.1f, 0.9f);

				FontLib::get().glPrint("%0.1f FPS, %i Particles", GlobalTime::get().fps/(numSamples+1), ParticleMgr::get().numParticles);

				if(p)
				{

					glRasterPos2f(0.1f, 0.85f);

					FontLib::get().glPrint("Speed: %0.2f", p->getVelocity().magnitude());

					glRasterPos2f(0.1f, 0.80f);

					FontLib::get().glPrint("Position: <%0.2f, %0.2f, %0.2f>", p->getPos().x, p->getPos().y, p->getPos().z);

					glRasterPos2f(0.1f, 0.75f);

					FontLib::get().glPrint("Number of Objects: %d", ObjectMgr::get().getNumObj());

					glRasterPos2f(0.1f, 0.70f);

					FontLib::get().glPrint("Number of Hits: %d", p->getHits());

					glRasterPos2f(0.1f, 0.65f);

					FontLib::get().glPrint("Beam Heat: %0.1f%%, Beam Energy: %0.1f%%", p->getBeamHeat(), p->getBeamEnergy());

					glRasterPos2f(0.1f, 0.60f);

					FontLib::get().glPrint("Hull Strength %0.1f%%", p->getHull());
				}

			}
		}

		glRasterPos2f(0.85f, -1.0f);

		FontLib::get().glPrint("GL2 %s - %0.1f FPS", version.c_str(), GlobalTime::get().fps/(numSamples+1));


		processInput();

		if(renderCycle)
		{
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);

			SDL_GL_SwapBuffers();

			SDL_Delay(1);
		} else {

		}

		GlobalTime::get().calcDelta();

	}

}

void GraphicsEngine::renderDebugInfo()
{

}

void GraphicsEngine::processInput()
{
	Player *p = ((Player*)ObjectMgr::get().find("player"));

	if(p && !showTerminal)
	{
		if(keys[SDLK_UP])p->applyForce(p->getUp()*3.0f*p->getMass());
		if(keys[SDLK_DOWN])p->applyForce(p->getUp()*-3.0f*p->getMass());
		if(keys[SDLK_LEFT])p->applyForce(p->getRight()*-3.0f*p->getMass());
		if(keys[SDLK_RIGHT])p->applyForce(p->getRight()*3.0f*p->getMass());
		if(keys[SDLK_w]){
			p->rotateAxis(p->getRight(),(GlobalTime::get().frameSec*(20.0f)));
		}
		if(keys[SDLK_a]){
			p->rotateAxis(p->getUp(),-(GlobalTime::get().frameSec*(-20.0f)));
		}
		if(keys[SDLK_s]){
			p->rotateAxis(p->getRight(),(GlobalTime::get().frameSec*(-20.0f)));

		}
		if(keys[SDLK_d]){
			p->rotateAxis(p->getUp(),-(GlobalTime::get().frameSec*(20.0f)));

		}
		if(keys[SDLK_f]){
			if((SDL_GetTicks()-keyInterval)>300){
				p->toggleTracking();
				keyInterval=SDL_GetTicks();
			}
		}
		if(keys[SDLK_m]){
				p->matchVelocity(((Player*)p)->getTarget());
		}
		if(keys[SDLK_g]){
			if((SDL_GetTicks()-keyInterval)>1000){
				p->toggleRadarZoom();
				keyInterval=SDL_GetTicks();
			}
		}
		if(keys[SDLK_r] || Joystick::get().getButton(1)){
			if((SDL_GetTicks()-keyInterval)>300){
				p->targetNearestEnemy();
				keyInterval=SDL_GetTicks();
			}
		}

		if(keys[SDLK_u]){
			if((SDL_GetTicks()-keyInterval)>300){
				p->targetNearestAlly();
				keyInterval=SDL_GetTicks();
			}
		}

		if(keys[SDLK_i]){
			if((SDL_GetTicks()-keyInterval)>300){
				p->targetNearestMissile();
				keyInterval=SDL_GetTicks();
			}
		}

		if(keys[SDLK_t]){
			if((SDL_GetTicks()-keyInterval)>300){
				p->nextTarget();
				keyInterval=SDL_GetTicks();
			}
		}

		if(keys[SDLK_y]){
			if((SDL_GetTicks()-keyInterval)>300){
				p->prevTarget();
				keyInterval=SDL_GetTicks();
			}
		}

		if(keys[SDLK_SPACE] || Joystick::get().getButton(4)){
			p->fireMissile();
		}

		if(keys[SDLK_b] || Joystick::get().getButton(0)){
			p->activateBeam();
		}

		if(keys[SDLK_F2])ShaderMgr::get().disable();
		if(keys[SDLK_F1])ShaderMgr::get().enable();

		if(curSample == 0)
		{
			if(keys[SDLK_F3])numSamples=0;
			if(keys[SDLK_F4])numSamples=1;
			if(keys[SDLK_F5])numSamples=2;
			if(keys[SDLK_F6])numSamples=10;
			if(keys[SDLK_F7])numSamples=20;
		}

		if(keys[SDLK_F8]) ObjectMgr::get().enableAI();
		if(keys[SDLK_F9]) ObjectMgr::get().disableAI();

		if(keys[SDLK_l])
		{
			if((SDL_GetTicks()-keyInterval)>300){
				renderPlayer=!renderPlayer;
				keyInterval=SDL_GetTicks();
			}
		}


		if(Joystick::get().getButton(2) || keys[SDLK_z])
		{
			//p->applyForce(p->getLook()*24.0f*((double)(32767-Joystick::get().getAxis(3))));
			double thrustPercent;
			double joypos = (double)(32767-Joystick::get().getAxis(3));
			if(joypos>50000) thrustPercent = 100.0f;
			else thrustPercent = joypos/500.0f;

			p->thrust(thrustPercent);
		}
		if(Joystick::get().getButton(3) || keys[SDLK_x])
		{
			p->stop();
		}
		if(Joystick::get().getButton(5))
		{
			p->applyForce(p->getUp()*(((double)(Joystick::get().getAxis(1)))/32768.0f)*-1.0f*3.0f*p->getMass());
			p->applyForce(p->getRight()*(((double)(Joystick::get().getAxis(0)))/32768.0f)*3.0f*p->getMass());
		} else {
			p->rotateAxis(p->getRight(),(GlobalTime::get().frameSec*((double)Joystick::get().getAxis(1))/300.0f));
			p->rotateAxis(p->getUp(),-(GlobalTime::get().frameSec*((double)Joystick::get().getAxis(0))/300.0f));
			//p->applyTorque((p->getRight()*((double)Joystick::get().getAxis(1))+p->getUp()*-((double)Joystick::get().getAxis(0)))*GlobalTime::get().frameSec*100000.0f);

		}
		p->rotateAxis(p->getLook(),((GlobalTime::get().frameSec*((double)Joystick::get().getAxis(2))/300.0f)));
		/*p->applyTorque(p->getLook()*((double)Joystick::get().getAxis(2))*GlobalTime::get().frameSec*100000.0f);
		if(abs(Joystick::get().getAxis(1))<500)
			p->applyTorque(p->getRight()*(p->getRight()*p->getOmega())*-1*p->getMomentOfInertia());
		if(abs(Joystick::get().getAxis(0))<500)
			p->applyTorque(p->getUp()*(p->getUp()*p->getOmega())*-1*p->getMomentOfInertia());
		if(abs(Joystick::get().getAxis(2))<500)
			p->applyTorque(p->getLook()*(p->getLook()*p->getOmega())*-1*p->getMomentOfInertia());*/
	}
	else
	{
		term->getInput(&event);
		glRasterPos2f(-0.9f, 0.9f);
		term->render();
	}

	if(keys[SDLK_BACKQUOTE])
	{
		if((SDL_GetTicks()-keyInterval)>500){
			showTerminal=!showTerminal;
			//else SDL_EnableKeyRepeat(1, 1);
			keyInterval=SDL_GetTicks();
		}

	}

	if(keys[SDLK_ESCAPE]) done=true;

	if(keys[SDLK_PRINT])
	{
		if((SDL_GetTicks()-screenshotKeyInterval)>1000)
		{
			screenShot();
			//delete pixels;
			screenshotKeyInterval=SDL_GetTicks();
		}

	}
}

bool GraphicsEngine::end()
{
	return true;
}



