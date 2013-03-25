#include "PlayerStatusIndicator.h"
#include "Player.h"

PlayerStatusIndicator::PlayerStatusIndicator() {
  parent = NULL;
  tex = "";
}

PlayerStatusIndicator::PlayerStatusIndicator(Object *parent, std::string tex) {
  this->parent = parent;
  this->tex = tex;
}

PlayerStatusIndicator::~PlayerStatusIndicator() {

}

void PlayerStatusIndicator::render() {
  if (parent && parent->getObjectType() == "player") {
    glDisable(GL_LIGHTING);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    double m[16];
    Camera::get().getMatrix(m);

    glPushMatrix();

    glLoadIdentity();

    Camera::get().setPerspective();

    glTranslatef(Camera::get().look.x / 0.8f, Camera::get().look.y / 0.8f,
                 Camera::get().look.z / 0.8f);
    glTranslatef(Camera::get().up.x * -0.52f, Camera::get().up.y * -0.52f,
                 Camera::get().up.z * -0.52f);
    glTranslatef(Camera::get().right.x * -0.95f, Camera::get().right.y * -0.95f,
                 Camera::get().right.z * -0.95f);
    glScalef(0.08f, 0.08f, 0.08f);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);

    glMultMatrixd(m);
    //glTranslatef(-0.75f,0.0f,1.0f);
    glScalef(1.25f, 1.25f, 1.0f);
    TextureMgr::get().use(tex);
    float red = (100.0f - ((Player*) parent)->getHull()) / 100.0f;
    float green = ((Player*) parent)->getHull() / 100.0f;
    glBegin(GL_QUADS);
    glColor4f(red, green, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnd();

    //glTranslatef(-0.1f,0.0f,0.0f);
    glDisable(GL_TEXTURE_2D);
    float energy = ((Player*) parent)->getBeamEnergy() / 50.0f - 1.0f;
    float heat = ((Player*) parent)->getBeamHeat() / 50.0f - 1.0f;
    glTranslatef(0.0f, -1.5f, 0.0f);
    glPushMatrix();
    glScalef(1.0f, 0.1f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex3f(energy, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(energy, 1.0f, 0.0f);
    glVertex3f(energy, -1.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnd();
    glPopMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f);
    glPushMatrix();
    glScalef(1.0f, 0.1f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex3f(heat, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(heat, 1.0f, 0.0f);
    glVertex3f(heat, -1.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnd();
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glColor4f(red, green, 0.0f, 1.0f);

    glRasterPos3f(-0.84f, -0.76f, -0.5f);
    FontLib::get().glPrint("%0.1f", ((Player*) parent)->getHull());

    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glEnable(GL_LIGHTING);
  }
}
