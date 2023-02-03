#ifndef GLWAFERVIEW_H
#define GLWAFERVIEW_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShader>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class GLWaferView : public QOpenGLWidget,
	public QOpenGLExtraFunctions
{
	Q_OBJECT

public:
	GLWaferView(QWidget* parent = 0);
	~GLWaferView();
protected:
	void initializeGL();             //初始化OpenGL//
	void resizeGL(int w, int h);     //调整oeenGL的显示窗口//
	void paintGL();                  //绘制opengl图像//
private:
	void InitShader();
	void InitBuffer();
private:
	QOpenGLShaderProgram shader;
	QOpenGLBuffer* vertexBuffer;
	QOpenGLBuffer* indexBuffer;
	float viewPortWidth;
	float viewPortHeight;

};

#endif // GLWAFERVIEW_H
