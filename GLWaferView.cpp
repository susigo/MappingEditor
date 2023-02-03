﻿#include "GLWaferView.h"

QString vertexShaderSource =
"#version 330 core\n\
layout (location = 0) in vec3 aPos;\n\
void main()\n\
{\n\
gl_Position = vec4(aPos, 1.0);\n\
}";
QString fragmentShaderSource =
"#version 330 core\n\
out vec4 FragColor;\n\
void main()\n\
{\n\
FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n\
}";

float vertices[] = {
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
   -0.5f, -0.5f, 0.0f,
   -0.5f,  0.5f, 0.0f
};

unsigned int indices[] =
{
	0, 1, 3,
	1, 2, 3
};

GLWaferView::GLWaferView(QWidget* parent)
	: QOpenGLWidget(parent)
	, viewPortWidth(300.0)
	, viewPortHeight(300.0)
{
}

GLWaferView::~GLWaferView()
{
	delete vertexBuffer;
	delete indexBuffer;
}

void GLWaferView::initializeGL()
{
	initializeOpenGLFunctions();
	glViewport(0, 0, viewPortWidth, viewPortHeight);
	glEnable(GL_DEPTH_TEST);

	InitShader();
	InitBuffer();
}

void GLWaferView::resizeGL(int w, int h)
{
	viewPortWidth = w;
	viewPortHeight = h;

	glViewport(0, 0, viewPortWidth, viewPortHeight);
}

void GLWaferView::paintGL()
{
	resize(viewPortWidth, viewPortHeight);
	glViewport(0, 0, viewPortWidth, viewPortHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	indexBuffer->bind();
	shader.bind();
	shader.enableAttributeArray("aPos");
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	shader.disableAttributeArray("aPos");
	shader.release();
	indexBuffer->release();
}
void GLWaferView::InitShader()
{
	shader.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	shader.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	shader.link();
}

void GLWaferView::InitBuffer()
{
	vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	indexBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

	shader.bind();
	vertexBuffer->create();
	vertexBuffer->bind();
	vertexBuffer->allocate(vertices, sizeof(vertices));
	vertexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
	shader.setAttributeBuffer("aPos", GL_FLOAT, 0, 3, 12);
	vertexBuffer->release();
	shader.release();

	indexBuffer->create();
	indexBuffer->bind();
	indexBuffer->allocate(indices, sizeof(indices));
	indexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
	indexBuffer->release();
}