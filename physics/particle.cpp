#include "particle.h"

ParticleMgr::ParticleMgr() {
//	if(!particles){
  std::cout << "[Starting Particle Engine]" << std::endl;
  //particles=new Particle[MAX_PARTICLES];
  for (int i = 0; i < MAX_PARTICLES; i++) {
    particles[i].state = 0;
    particles[i].type = 1;
    particles[i].velocity *= 0;
    particles[i].pos *= 0;
    particles[i].startColor.r = 0;
    particles[i].startColor.b = 0;
    particles[i].startColor.g = 0;
    particles[i].startColor.a = 0;
    particles[i].curColor.r = 0;
    particles[i].curColor.g = 0;
    particles[i].curColor.b = 0;
    particles[i].curColor.a = 0;
    particles[i].endColor.r = 0;
    particles[i].endColor.g = 0;
    particles[i].endColor.b = 0;
    particles[i].endColor.a = 0;
    particles[i].curScale = 0;
    particles[i].endScale = 0;
    particles[i].counter = 0;
    particles[i].lifetime = 0;
    particles[i].fadestep = 0;

  }
  //}

}
ParticleMgr::~ParticleMgr() {
  //delete particles;
  /*try {
   delete particles;
   } catch (std::exception e)
   {
   std::cout<<e.what()<<std::endl;
   }*/

  std::cout << "[Ending Particle Engine]" << std::endl;
}

void ParticleMgr::startParticle(int type, glRGBA color, std::string t,
                                float scale, float endScale, long lifetime,
                                Vector ps, Vector v) {
  int pindex = -1;
  for (int i = 0; i < MAX_PARTICLES; i++)
    if (particles[i].state == 0) {
      pindex = i;
      break;
    }
  if (pindex == -1)
    return;

  particles[pindex].state = 1;
  particles[pindex].type = type;
  particles[pindex].pos = (FVector) {ps.x,ps.y,ps.z};
  particles[pindex].velocity = (FVector) {v.x,v.y,v.z};
  particles[pindex].counter = SDL_GetTicks();
  particles[pindex].lifetime = lifetime;
  particles[pindex].fadestep = color.a / ((float) lifetime);
  particles[pindex].scale = scale;
  particles[pindex].curScale = scale;
  particles[pindex].endScale = endScale;
  particles[pindex].scalestep = (endScale - scale) / ((float) lifetime);
  particles[pindex].startColor = color;
  particles[pindex].endColor = color;
  particles[pindex].endColor.a = 0;
  particles[pindex].tex = t;
  particles[pindex].texptr = TextureMgr::get().find(t);
  if (type == 1) {
    particles[pindex].curColor = color;
  }
  if (type == 0) {
    particles[pindex].curColor = color;
    particles[pindex].curColor.a = (rand() % 100) / 100;
  }
}

void ParticleMgr::handle() {
  //float t=(globalTime);
  numParticles = 0;
  Vector temp;
  for (int i = 0; i < MAX_PARTICLES; i++) {
    if (particles[i].state == 1) {
      temp = Vector(particles[i].pos.x, particles[i].pos.y, particles[i].pos.z);
      if (!Camera::get().sphereInFrustum(temp, particles[i].curScale * .03))
        particles[i].state = 0;
      else {
        numParticles++;
        particles[i].pos += particles[i].velocity
            * (GlobalTime::get().frameSec);

        particles[i].curScale += particles[i].scalestep
            * (GlobalTime::get().frameTime);
        if (particles[i].type == 0) {
          particles[i].curColor.a = ((float) (rand() % 100)) / 100;
          if ((SDL_GetTicks() - particles[i].counter) > particles[i].lifetime) {
            particles[i].state = 0;
          }

        }

        if (particles[i].type == 1) {

          float t = (float) (SDL_GetTicks() - particles[i].counter);
          particles[i].curColor.a -= particles[i].fadestep
              * (GlobalTime::get().frameTime);
          if (t > particles[i].lifetime) {

            particles[i].state = 0;
          }

        }
      }
    }
  }
}

void ParticleMgr::render() {
  glPushMatrix();
  glDisable(GL_LIGHTING);
  glMaterialfv(GL_BACK, GL_EMISSION, (const float[4]) {1.0f,1.0f,1.0f,1.25f});
  //glEnable (GL_BLEND);
  glDepthMask(GL_FALSE);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  //glPointSize(4.0f);

  glEnable(GL_POINT_SPRITE);
  glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
  //glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_FALSE);
  glEnable(GL_POINT_SMOOTH);

  glPointParameterfv(GL_POINT_SIZE_MAX, (const float[1]) {5000.0f});
  /*
   float scale = 0.01f;
   float s[3] = {0.0f, 0.0f, scale};
   glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, s);
   glPointSize(100.0f);
   if(particles[0].texptr)particles[0].texptr->bind();
   */

  for (int i = 0; i < MAX_PARTICLES; i++) {
    if (particles[i].state == 1) {
      float scale = 1.0f / (particles[i].curScale * particles[i].curScale);
      float s[3] = { 0.0f, 0.0f, scale };
      glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, s);
      glPointSize(100.0f * particles[i].curScale);
      particles[i].texptr->bind();
      glBegin(GL_POINTS);
      glColor4f(particles[i].curColor.r, particles[i].curColor.g,
                particles[i].curColor.b, particles[i].curColor.a);
      glVertex3f(particles[i].pos.x, particles[i].pos.y, particles[i].pos.z);
      glEnd();
    }
  }

  /*
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);

   glColorPointer(4,GL_FLOAT,sizeof(Particle),&particles[0].curColor.r);
   glVertexPointer(3,GL_FLOAT,sizeof(Particle),&particles[0].pos.x);

   glDrawArrays(GL_POINTS,0,numParticles);

   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_VERTEX_ARRAY);
   */
  glDisable(GL_POINT_SPRITE);
  glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_FALSE);
  glDisable(GL_POINT_SMOOTH);

  /*
   double m[16];
   Camera::get().getMatrix(m);
   for(int i=0;i<MAX_PARTICLES;i++)
   {
   if(particles[i].state==1)
   {

   glPushMatrix();
   //glLoadIdentity();
   //glDisable(GL_TEXTURE_2D);

   //TextureMgr::get().UseTexture(particles[i].tex);
   particles[i].texptr->bind();

   //glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_BLEND);
   //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
   //glScalef(2.0f,2.0f,2.0f);

   //Float translation????? Speed vs. accuracy????
   glTranslatef(particles[i].pos.x,particles[i].pos.y,particles[i].pos.z);
   glScalef(.03f*particles[i].curScale,.03f*particles[i].curScale,.03f*particles[i].curScale);


   glMultMatrixd(m);
   glRotatef(90.0f,0.0f,0.0f,1.0f);
   glBegin(GL_QUADS);

   glColor4f(particles[i].curColor.r,particles[i].curColor.g,particles[i].curColor.b, particles[i].curColor.a);
   glTexCoord2f(0.0f,0.0f);
   glVertex3f(1.0f,-1.0f,0.0f);
   glTexCoord2f(1.0f,0.0f);
   glVertex3f(-1.0f,-1.0f,0.0f);
   glTexCoord2f(1.0f,1.0f);
   glVertex3f(-1.0f,1.0f,0.0f);
   glTexCoord2f(0.0f,1.0f);
   glVertex3f(1.0f,1.0f,0.0f);

   //glVertex2f(particles[i].x,particles[i].y);
   glColor4f(1.0f,1.0f,1.0f,1.0f);
   glEnd();
   //glEnable(GL_TEXTURE_2D);
   glPopMatrix();
   }

   }*/
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  glDepthMask(GL_TRUE);
  glEnable(GL_LIGHTING);
  glPopMatrix();
}

void ParticleMgr::startExplosion(std::string t, int numParticles, float scale,
                                 float endScale, long lifetime, Vector pos,
                                 Vector velocity, float explosionSpeed) {
  int part = (int) sqrt(numParticles);
  if (!part)
    return;
  float stepA = 360 / part;
  float stepB = 180 / part;
  for (int i = 0; i < part; i++) {
    for (int ii = 0; ii < part; ii++) {
      Vector v;
      v.x = cos(DEG2RAD(i*stepA)) * sin(DEG2RAD(ii*stepB)) * explosionSpeed;
      v.y = sin(DEG2RAD(i*stepA)) * sin(DEG2RAD(ii*stepB)) * explosionSpeed;
      v.z = cos(DEG2RAD(i*stepA)) * explosionSpeed;
      startParticle(1, (glRGBA) {rand()%10/10.0f,0.2f,rand()%10/10.0f,1.0f}, t,
                    scale, endScale, lifetime, pos, velocity + v);
    }
  }
}
