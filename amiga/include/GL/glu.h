/* The two GLU calls BlockOut II makes (amiga/amiga_glu.c): the OpenGPU
 * kit has no GLU. The AmiCradle Team. GPL 2 or later, like BlockOut II. */
#ifndef AMIGA_GLU_H
#define AMIGA_GLU_H
#include <GL/gl.h>
#ifdef __cplusplus
extern "C" {
#endif
void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
void gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ,
               GLdouble centerX, GLdouble centerY, GLdouble centerZ,
               GLdouble upX, GLdouble upY, GLdouble upZ);
#ifdef __cplusplus
}
#endif
#endif
