

#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

bool isAnimationRunning = true; // Controls whether the windmill spins automatically
float bladeAngle = 0.0f;    // Controls the rotation of the windmill blades
float cloudOffset = 0.0f;   // Controls the left-to-right movement of the clouds


void drawFilledCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        glVertex2f(r * cosf(theta) + cx, r * sinf(theta) + cy);
    }
    glEnd();
}


void drawFilledOval(float cx, float cy, float rx, float ry, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        glVertex2f(rx * cosf(theta) + cx, ry * sinf(theta) + cy);
    }
    glEnd();
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();  //Resets the transformation matrix — no rotation, no translation, fresh start.



    // Draw Sky (Gradient from deep blue to light blue)
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.49f, 0.84f); // deep blue
    glVertex2f(-50.0f, 50.0f);
    glVertex2f(50.0f, 50.0f);
    glColor3f(0.42f, 0.81f, 0.97f); //  light blue
    glVertex2f(50.0f, -15.0f);
    glVertex2f(-50.0f, -15.0f);
    glEnd();

    // Draw Sun
    glColor3f(0.99f, 0.95f, 0.22f); // Yellow
    drawFilledCircle(0.0f, 25.0f, 5.0f, 40);


    // Draw Moving Clouds
    glPushMatrix();
    glTranslatef(cloudOffset, 0.0f, 0.0f);


    // Cloud 1
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(5.0f, 26.0f, 3.5f, 30);
    drawFilledCircle(11.0f, 28.0f, 4.5f, 30);
    drawFilledCircle(17.0f, 27.0f, 4.0f, 30);
    drawFilledCircle(22.0f, 25.0f, 3.0f, 30);
    glBegin(GL_QUADS); // Cloud base block
    glVertex2f(5.0f, 26.0f);
    glVertex2f(22.0f, 25.0f);
    glVertex2f(22.0f, 22.0f);
     glVertex2f(5.0f, 22.0f);
    glEnd();


    // Cloud 2
    drawFilledCircle(-25.0f, 27.0f, 4.0f, 30);
    drawFilledCircle(-19.0f, 29.0f, 5.0f, 30);
    drawFilledCircle(-13.0f, 26.0f, 3.5f, 30);
    glBegin(GL_QUADS); // Cloud base block
    glVertex2f(-25.0f, 27.0f);
    glVertex2f(-13.0f, 26.0f);
    glVertex2f(-13.0f, 23.0f);
    glVertex2f(-25.0f, 23.0f);
    glEnd();

    glPopMatrix();



    // Draw Hills
    glBegin(GL_POLYGON);
    glColor3f(0.53f, 0.75f, 0.24f); // Light green
    glVertex2f(-50.0f, -15.0f);
    glVertex2f(-20.0f, -5.0f);
    glVertex2f(15.0f, -10.0f);
    glVertex2f(50.0f, 5.0f);
    glVertex2f(50.0f, -50.0f);
    glVertex2f(-50.0f, -50.0f);
    glEnd();


    // Draw Green Field
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.69f, 0.18f); // Field top color
    glVertex2f(-50.0f, -25.0f);
    glVertex2f(50.0f, -33.0f);
    glColor3f(0.32f, 0.51f, 0.10f); // Field bottom color (darker)
    glVertex2f(50.0f, -50.0f);
    glVertex2f(-50.0f, -50.0f);
    glEnd();

    // Draw Brown Road
    glBegin(GL_QUADS);
    glColor3f(0.48f, 0.35f, 0.22f);
    glVertex2f(-50.0f, -42.0f);
    glVertex2f(50.0f, -44.0f);
    glVertex2f(50.0f, -50.0f);
    glVertex2f(-50.0f, -50.0f);
    glEnd();


    // --- HOUSE ---
    // Base
    glColor3f(0.92f, 0.81f, 0.74f);
    glBegin(GL_QUADS);
    glVertex2f(20.0f, -5.0f);
    glVertex2f(42.0f, -5.0f);
    glVertex2f(42.0f, -15.0f);
    glVertex2f(20.0f, -15.0f);
    glEnd();


    // Bottom Dark Brown Base
    glColor3f(0.53f, 0.38f, 0.29f);
    glBegin(GL_QUADS);
    glVertex2f(20.0f, -13.5f);
    glVertex2f(42.0f, -13.5f);
    glVertex2f(42.0f, -15.0f);
    glVertex2f(20.0f, -15.0f);
    glEnd();

    // Main Roof
    glColor3f(0.68f, 0.25f, 0.24f);
    glBegin(GL_QUADS);
    glVertex2f(22.0f, 3.0f);
    glVertex2f(40.0f, 3.0f);
    glVertex2f(43.0f, -5.0f);
    glVertex2f(19.0f, -5.0f);
    glEnd();

    // Front Extended Wall
    glColor3f(0.95f, 0.88f, 0.79f);
    glBegin(GL_QUADS);
    glVertex2f(25.0f, -2.0f);
    glVertex2f(32.0f, -2.0f);
    glVertex2f(32.0f, -15.0f);
     glVertex2f(25.0f, -15.0f);
    glEnd();

    // Front Roof Trim
    glColor3f(0.78f, 0.35f, 0.32f);
    glBegin(GL_TRIANGLES);
    glVertex2f(28.5f, 3.0f);
    glVertex2f(23.5f, -2.2f);
    glVertex2f(33.5f, -2.2f);
    glEnd();

    // Inner Front Roof
    glColor3f(0.68f, 0.25f, 0.24f);
    glBegin(GL_TRIANGLES);
    glVertex2f(28.5f, 2.2f);
    glVertex2f(24.5f, -2.0f);
    glVertex2f(32.5f, -2.0f);
    glEnd();

    // Windows (Left, Right 1, Right 2, Upper Roof)
    glColor3f(0.40f, 0.35f, 0.32f);
    glBegin(GL_QUADS);
    glVertex2f(21.0f, -6.0f);  glVertex2f(24.0f, -6.0f);  glVertex2f(24.0f, -11.0f); glVertex2f(21.0f, -11.0f); // Left
    glVertex2f(33.0f, -6.0f);  glVertex2f(36.0f, -6.0f);  glVertex2f(36.0f, -11.0f); glVertex2f(33.0f, -11.0f); // Right 1
    glVertex2f(37.5f, -6.0f);  glVertex2f(40.5f, -6.0f);  glVertex2f(40.5f, -11.0f); glVertex2f(37.5f, -11.0f); // Right 2
    glVertex2f(27.5f, 0.5f);   glVertex2f(29.5f, 0.5f);   glVertex2f(29.5f, -1.5f);  glVertex2f(27.5f, -1.5f);  // Top
    glEnd();

    glColor3f(0.45f, 0.58f, 0.63f); // Glass
    glBegin(GL_QUADS);
    glVertex2f(21.2f, -6.2f);  glVertex2f(23.8f, -6.2f);  glVertex2f(23.8f, -10.8f); glVertex2f(21.2f, -10.8f); // Left
    glVertex2f(33.2f, -6.2f);  glVertex2f(35.8f, -6.2f);  glVertex2f(35.8f, -10.8f); glVertex2f(33.2f, -10.8f); // Right 1
    glVertex2f(37.7f, -6.2f);  glVertex2f(40.3f, -6.2f);  glVertex2f(40.3f, -10.8f); glVertex2f(37.7f, -10.8f); // Right 2
    glVertex2f(27.7f, 0.3f);   glVertex2f(29.3f, 0.3f);   glVertex2f(29.3f, -1.3f);  glVertex2f(27.7f, -1.3f);  // Top
    glEnd();

    // Door and Frame
    glColor3f(0.40f, 0.32f, 0.28f); // Frame
    glBegin(GL_QUADS);
    glVertex2f(26.8f, -4.8f);
    glVertex2f(30.2f, -4.8f);
    glVertex2f(30.2f, -15.0f);
    glVertex2f(26.8f, -15.0f);
    glEnd();
    glColor3f(0.61f, 0.49f, 0.42f); // Door
    glBegin(GL_QUADS);
    glVertex2f(27.0f, -5.0f);
    glVertex2f(30.0f, -5.0f);
    glVertex2f(30.0f, -15.0f);
    glVertex2f(27.0f, -15.0f);
    glEnd();
    glColor3f(0.85f, 0.75f, 0.35f); // Doorknob
    glBegin(GL_QUADS);
    glVertex2f(29.4f, -9.8f);
    glVertex2f(29.7f, -9.8f);
     glVertex2f(29.7f, -10.3f);
     glVertex2f(29.4f, -10.3f);
    glEnd();



        // Pine Tree 1 (Far Left)
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-43.5f, -15.0f);
    glVertex2f(-42.5f, -15.0f);
    glVertex2f(-42.5f, -6.0f);
    glVertex2f(-43.5f, -6.0f);
    glEnd();
    glColor3f(0.0f, 0.45f, 0.24f); // Leaves
    drawFilledOval(-43.0f, -5.0f, 1.8f, 7.0f, 30);

    // Pine Tree 2 (Far Left)
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-39.5f, -15.0f);
    glVertex2f(-38.5f, -15.0f);
    glVertex2f(-38.5f, -9.0f);
    glVertex2f(-39.5f, -9.0f);
    glEnd();
    glColor3f(0.0f, 0.45f, 0.2f); // Leaves
    drawFilledOval(-39.0f, -4.0f, 2.2f, 8.5f, 30);


    // --- WINDMILL ---
    // Windmill Base Oval
    glColor3f(0.84f, 0.85f, 0.84f);
    drawFilledOval(-23.0f, -32.0f, 16.0f, 3.0f, 40);

    // Windmill Bottom Block
    glColor3f(0.18f, 0.13f, 0.09f);
    glBegin(GL_QUADS);
    glVertex2f(-29.5f, -22.0f);
    glVertex2f(-16.5f, -22.0f);
    glVertex2f(-16.5f, -32.0f);
    glVertex2f(-29.5f, -32.0f);
    glEnd();

    // Windmill Door
    glColor3f(0.55f, 0.08f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(-24.5f, -25.0f);
    glVertex2f(-21.5f, -25.0f);
    glVertex2f(-21.5f, -32.0f);
    glVertex2f(-24.5f, -32.0f);
    glEnd();

    // Windmill Windows
    glColor3f(0.95f, 0.95f, 0.92f);
    glBegin(GL_QUADS);
    glVertex2f(-28.7f, -25.0f); glVertex2f(-27.3f, -25.0f); glVertex2f(-27.3f, -28.0f); glVertex2f(-28.7f, -28.0f); // 1
    glVertex2f(-26.7f, -25.0f); glVertex2f(-25.3f, -25.0f); glVertex2f(-25.3f, -28.0f); glVertex2f(-26.7f, -28.0f); // 2
    glVertex2f(-20.7f, -25.0f); glVertex2f(-19.3f, -25.0f); glVertex2f(-19.3f, -28.0f); glVertex2f(-20.7f, -28.0f); // 3
    glVertex2f(-18.7f, -25.0f); glVertex2f(-17.3f, -25.0f); glVertex2f(-17.3f, -28.0f); glVertex2f(-18.7f, -28.0f); // 4
    glEnd();

    // Windmill Main Tower Body
    glBegin(GL_QUADS);
    glColor3f(0.80f, 0.40f, 0.15f);
    glVertex2f(-26.0f, 15.0f);
    glColor3f(0.92f, 0.53f, 0.23f);
    glVertex2f(-20.0f, 15.0f);
    glColor3f(0.70f, 0.32f, 0.08f);
    glVertex2f(-16.5f, -22.0f);
    glColor3f(0.58f, 0.25f, 0.05f);
    glVertex2f(-29.5f, -22.0f);
    glEnd();

    // Windmill Decorative Bricks
glColor3f(0.95f, 0.65f, 0.35f);
    glBegin(GL_QUADS);

    // Brick 1
    glVertex2f(-24.0f, 8.0f);
    glVertex2f(-22.5f, 8.0f);
    glVertex2f(-22.5f, 7.0f);
    glVertex2f(-24.0f, 7.0f);

    // Brick 2
    glVertex2f(-21.0f, 0.0f);
    glVertex2f(-19.5f, 0.0f);
    glVertex2f(-19.5f, -1.0f);
    glVertex2f(-21.0f, -1.0f);

    // Brick 3
    glVertex2f(-25.0f, -6.0f);
    glVertex2f(-23.5f, -6.0f);
    glVertex2f(-23.5f, -7.0f);
    glVertex2f(-25.0f, -7.0f);

    // Brick 4
    glVertex2f(-19.0f, -12.0f);
    glVertex2f(-17.5f, -12.0f);
    glVertex2f(-17.5f, -13.0f);
    glVertex2f(-19.0f, -13.0f);

    // Brick 5
    glVertex2f(-26.0f, -18.0f);
    glVertex2f(-24.5f, -18.0f);
    glVertex2f(-24.5f, -19.0f);
    glVertex2f(-26.0f, -19.0f);

    glEnd();


    // Windmill Dome/Roof
    glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.33f, 0.18f);
    for (int i = 0; i <= 180; i++) {
        float theta = M_PI * float(i) / 180.0f;
        if(i == 90) glColor3f(0.68f, 0.44f, 0.26f); // Change color halfway
        glVertex2f(-23.0f + 3.1f * cosf(theta), 15.0f + 4.5f * sinf(theta));
    }
    glEnd();



    // Windmill Rotating Blades
    glPushMatrix();
    glTranslatef(-23.0f, 16.5f, 0.0f);        // Move pivot point to top of windmill
    glRotatef(bladeAngle, 0.0f, 0.0f, 1.0f);  // Rotate based on timer variable



    // Blade 1 (0 degrees)

    glPushMatrix();
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);

    // Wooden stick
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.31f, 0.48f);
    glVertex2f(-0.3f, 0.0f);  glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();

    // Cloth sail
    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.20f, 0.69f);
    glVertex2f(-0.3f, 6.0f);   glVertex2f(-4.8f, 6.0f);
    glColor3f(0.42f, 0.60f, 0.81f);
    glVertex2f(-4.8f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();
    glPopMatrix();



    // Blade 2 (90 degrees)

    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

    // Wooden stick
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.31f, 0.48f);
    glVertex2f(-0.3f, 0.0f);  glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();

    // Cloth sail
    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.20f, 0.69f);
    glVertex2f(-0.3f, 6.0f);   glVertex2f(-4.8f, 6.0f);
    glColor3f(0.42f, 0.60f, 0.81f);
    glVertex2f(-4.8f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();
    glPopMatrix();



    // Blade 3 (180 degrees)

    glPushMatrix();
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

    // Wooden stick
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.31f, 0.48f);
    glVertex2f(-0.3f, 0.0f);  glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();

    // Cloth sail
    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.20f, 0.69f);
    glVertex2f(-0.3f, 6.0f);   glVertex2f(-4.8f, 6.0f);
    glColor3f(0.42f, 0.60f, 0.81f);
    glVertex2f(-4.8f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();
    glPopMatrix();



    // Blade 4 (270 degrees)

    glPushMatrix();
    glRotatef(270.0f, 0.0f, 0.0f, 1.0f);

    // Wooden stick
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.31f, 0.48f);
    glVertex2f(-0.3f, 0.0f);  glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();

    // Cloth sail
    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.20f, 0.69f);
    glVertex2f(-0.3f, 6.0f);   glVertex2f(-4.8f, 6.0f);
    glColor3f(0.42f, 0.60f, 0.81f);
    glVertex2f(-4.8f, 20.0f);  glVertex2f(-0.3f, 20.0f);
    glEnd();
    glPopMatrix();

    // Central connector for blades
    glColor3f(0.60f, 0.15f, 0.15f); drawFilledCircle(0.0f, 0.0f, 1.5f, 30);
    glColor3f(0.20f, 0.35f, 0.55f); drawFilledCircle(0.0f, 0.0f, 0.8f, 30);
    glPopMatrix();


    // --- TREES ---
    // Small Tree 1 (Center-Right Foreground)
    glColor3f(0.37f, 0.38f, 0.20f); // Trunk
    glBegin(GL_QUADS);
    glVertex2f(25.5f, -40.0f);
    glVertex2f(26.5f, -40.0f);
    glVertex2f(26.5f, -30.0f);
    glVertex2f(25.5f, -30.0f);
    glEnd();
    glColor3f(0.35f, 0.78f, 0.15f);
    drawFilledCircle(26.0f, -27.0f, 5.5f, 30);

    // Small Tree 2 (Far-Right Foreground)
    glColor3f(0.37f, 0.38f, 0.20f);
    glBegin(GL_QUADS);
    glVertex2f(36.5f, -40.0f);
    glVertex2f(37.5f, -40.0f);
    glVertex2f(37.5f, -31.0f);
    glVertex2f(36.5f, -31.0f);
    glEnd();
    glColor3f(0.47f, 0.82f, 0.18f); // Leaves
    drawFilledCircle(37.0f, -28.5f, 4.8f, 30);



    // Tall Tree (Far Right)
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(45.5f, -35.0f); glVertex2f(46.5f, -35.0f);
    glVertex2f(46.5f, -20.0f); glVertex2f(45.5f, -20.0f);
    glEnd();
    glColor3f(0.0f, 0.5f, 0.24f); // Leaves
    drawFilledOval(46.0f, -16.0f, 1.5f, 13.0f, 30);

    // Swap buffers to display the rendered frame
    glutSwapBuffers();
}

void timer(int value) {


    if (isAnimationRunning) {
        bladeAngle -= 0.5;
        if (bladeAngle < -360.0f) {
            bladeAngle += 360.0f;
        }

        // Move Clouds
        cloudOffset += 0.05f;
        if (cloudOffset > 80.0f) {
            cloudOffset = -80.0f;
        }

        // Tell OpenGL to redraw the screen
        glutPostRedisplay();
    }

    glutTimerFunc(16, timer, 0); // Keep the timer loop going
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
// NEW: Keyboard Callback Function
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
        case 'S':
            isAnimationRunning = !isAnimationRunning;
            break;
        case 'r':
        case 'R':
            bladeAngle -= 5.0f;
            glutPostRedisplay();
            break;
        case 'l':
        case 'L':
            bladeAngle += 5.0f;
            glutPostRedisplay();
            break;


    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 720);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Animated Landscape Scene");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(3000, timer, 0); // Start the animation loop

    glutMainLoop(); // Keep the program running
    return 0;
}
