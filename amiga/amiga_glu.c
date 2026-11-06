/* gluPerspective and gluLookAt for BlockOut II on AmigaOS (the OpenGPU kit
 * has no GLU): the matrices the GLU specification gives, multiplied onto
 * the current matrix with glMultMatrixd, as GLU's own do.
 * The AmiCradle Team. GPL 2 or later, like BlockOut II. */
#include <math.h>
#include <GL/glu.h>

void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	GLdouble m[16] = { 0 };
	GLdouble f = 1.0 / tan(fovy * M_PI / 360.0);

	if (aspect == 0.0 || zNear == zFar)
		return;
	m[0] = f / aspect;
	m[5] = f;
	m[10] = (zFar + zNear) / (zNear - zFar);
	m[11] = -1.0;
	m[14] = 2.0 * zFar * zNear / (zNear - zFar);
	glMultMatrixd(m);
}

static void normalize(GLdouble v[3])
{
	GLdouble r = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	if (r != 0.0) {
		v[0] /= r;
		v[1] /= r;
		v[2] /= r;
	}
}

static void cross(const GLdouble a[3], const GLdouble b[3], GLdouble out[3])
{
	out[0] = a[1] * b[2] - a[2] * b[1];
	out[1] = a[2] * b[0] - a[0] * b[2];
	out[2] = a[0] * b[1] - a[1] * b[0];
}

void gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ,
               GLdouble centerX, GLdouble centerY, GLdouble centerZ,
               GLdouble upX, GLdouble upY, GLdouble upZ)
{
	GLdouble f[3] = { centerX - eyeX, centerY - eyeY, centerZ - eyeZ };
	GLdouble up[3] = { upX, upY, upZ };
	GLdouble s[3], u[3];
	GLdouble m[16] = { 0 };

	normalize(f);
	cross(f, up, s);
	normalize(s);
	cross(s, f, u);
	m[0] = s[0]; m[4] = s[1]; m[8] = s[2];
	m[1] = u[0]; m[5] = u[1]; m[9] = u[2];
	m[2] = -f[0]; m[6] = -f[1]; m[10] = -f[2];
	m[15] = 1.0;
	glMultMatrixd(m);
	glTranslated(-eyeX, -eyeY, -eyeZ);
}
