#include "simpleExampleEffect.h"

//--------------------------------------------------------------
void simpleExampleEffect::setup(ofTexture &tex0) {
	// Enabled for 3d drawing
	ofEnableAlphaBlending();
	// Sets size of plane based on input texture
	plane.set(tex0.getWidth(), tex0.getHeight());
	// Load shaders
	colourful_shader.load("passthrough.vert", "negative.frag");
	bloom_thresthold_shader.load("passthrough.vert","thresthold.frag");
	bloom_shader_blur.load("passthrough.vert", "convolution.frag");
	blurGlitch_shader.load("passthrough.vert", "blurGlitch.frag");
	shadow_shader_blur.load("passthrough.vert", "shadow.frag");
	shadow_thresthold_shader.load("passthrough.vert", "negThresthold.frag");
	// Allocate FBOOs
	bloom_thresthold_fbo.allocate(tex0.getWidth(), tex0.getHeight(), GL_RGBA);
	bloom_fbo_blur.allocate(tex0.getWidth(), tex0.getHeight(), GL_RGBA);
	shadow_fbo_blur.allocate(tex0.getWidth(), tex0.getHeight(), GL_RGBA32F);
	shadow_thresthold_fbo.allocate(tex0.getWidth(), tex0.getHeight(), GL_RGBA32F);

	// Clear FBOs
	bloom_thresthold_fbo.begin();
	ofClear(0, 0, 0, 0);
	bloom_thresthold_fbo.end();

	bloom_fbo_blur.begin();
	ofClear(0, 0, 0, 0);
	bloom_fbo_blur.end();

	shadow_fbo_blur.begin();
	ofClear(0, 0, 0, 0);
	shadow_fbo_blur.end();

	shadow_thresthold_fbo.begin();
	ofClear(0, 0, 0, 0);
	shadow_thresthold_fbo.end();

	// Move camera to center cube
	cam.move(0, 0, 1400);

	plane.mapTexCoordsFromTexture(tex0);

}

//--------------------------------------------------------------
void simpleExampleEffect::update() {

}

//--------------------------------------------------------------
void simpleExampleEffect::draw(ofTexture &tex0) {
	ofEnableDepthTest();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);

	ofEnableAlphaBlending();

	cam.begin();
	//// Continuous rotations
	ofRotateYDeg(ofGetElapsedTimef() * 20);
	////ofRotateXDeg(ofGetElapsedTimef() * 30);

	ofTranslate(0, 0, 0.5*plane.getWidth());



	// Blur glitch shader
	blurGlitch_shader.begin();
	blurGlitch_shader.setUniformTexture("tex0", tex0, 0);
	blurGlitch_shader.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	blurGlitch_shader.setUniform1f("time", ofGetElapsedTimef());
	ofPushMatrix();
	plane.draw();
	ofPopMatrix();
	blurGlitch_shader.end();


	// Bloom
	//
	// Thresthold shader pass
	bloom_thresthold_shader.begin();
	bloom_thresthold_shader.setUniformTexture("tex0", tex0, 0);
	bloom_thresthold_shader.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	bloom_thresthold_fbo.begin();
	ofClear(0, 0, 0, 0);
	ofPushMatrix();
	ofTranslate(0.5*tex0.getWidth(), 0.5*tex0.getHeight());
	plane.draw();
	ofPopMatrix();
	bloom_thresthold_fbo.end();
	bloom_thresthold_shader.end();

		// Shadow
	//
	// Thresthold shader pass
	shadow_thresthold_shader.begin();
	shadow_thresthold_shader.setUniformTexture("tex0", tex0, 0);
	shadow_thresthold_shader.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	shadow_thresthold_fbo.begin();
	ofClear(0, 0, 0, 0);
	ofPushMatrix();
	ofTranslate(0.5*tex0.getWidth(), 0.5*tex0.getHeight());
	plane.draw();
	ofPopMatrix();
	shadow_thresthold_fbo.end();
	shadow_thresthold_shader.end();





	shadow_fbo_blur.begin();
	shadow_shader_blur.begin();
	shadow_shader_blur.setUniformTexture("tex0", shadow_thresthold_fbo.getTexture(), 1);
	shadow_shader_blur.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	shadow_shader_blur.setUniform2f("dir", 1.0, 0.0);
	shadow_shader_blur.setUniform1f("timeSin", sin(ofGetElapsedTimef()));
	ofClear(0, 0, 0, 0);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	plane.draw();
	ofPopMatrix();
	shadow_shader_blur.end();
	shadow_fbo_blur.end();





	//shadow_fbo_blur.draw(0, 0);

	ofPushMatrix();
	ofRotateYDeg(90);
	ofTranslate(0.5*plane.getWidth(), 0, 0.5*plane.getWidth());
	// Writing to the GL Depth Buffer is temporarily
	// disabled to allow the partially transparent bloom
	// texture do display over the opaque webcam image
	glDepthMask(GL_FALSE);
	// Draw webcam
	tex0.draw(tex0.getWidth() / 2, -tex0.getHeight() / 2, -tex0.getWidth(), tex0.getHeight());


	//shadow_fbo_blur.draw(0, 0);


	shadow_shader_blur.begin();
	shadow_shader_blur.setUniformTexture("tex0", shadow_fbo_blur.getTexture(), 1);
	shadow_shader_blur.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	shadow_shader_blur.setUniform2f("dir", 0.0, 1.0);
	shadow_shader_blur.setUniform1f("timeSin", sin(ofGetElapsedTimef()));
	//ofClear(0, 0, 0, 0);

	ofPushMatrix();
/*	ofRotateYDeg(90);
	ofTranslate(0.5*plane.getWidth(), 0, 0.5*plane.getWidth() + spacing)*/;
	glDepthMask(GL_TRUE);

	plane.draw();
	ofPopMatrix();
	shadow_shader_blur.end();
	ofPopMatrix();







	// Horizontal blur pass
	bloom_fbo_blur.begin();
	bloom_shader_blur.begin();
	bloom_shader_blur.setUniformTexture("tex0", bloom_thresthold_fbo.getTexture(), 1);
	bloom_shader_blur.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	bloom_shader_blur.setUniform2f("dir", 1.0, 0.0);
	bloom_shader_blur.setUniform1f("timeSin", sin(ofGetElapsedTimef()));
	ofClear(0, 0, 0, 0);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	plane.draw();
	ofPopMatrix();
	bloom_shader_blur.end();
	bloom_fbo_blur.end();

	
	ofPushMatrix();
	ofRotateYDeg(180);
	ofTranslate(0, 0, plane.getWidth());
	// Writing to the GL Depth Buffer is temporarily
	// disabled to allow the partially transparent bloom
	// texture do display over the opaque webcam image
	glDepthMask(GL_FALSE);
	// Draw webcam
	tex0.draw(tex0.getWidth()/2, -tex0.getHeight()/2, -tex0.getWidth(), tex0.getHeight());

	// Vertical blur pass
	bloom_shader_blur.begin();
	bloom_shader_blur.setUniformTexture("tex0", bloom_fbo_blur.getTexture(), 0);
	bloom_shader_blur.setUniform2f("texRes", tex0.getWidth(), tex0.getHeight());
	bloom_shader_blur.setUniform2f("dir", 0.0, 1.0);
	bloom_shader_blur.setUniform1f("timeSin", sin(ofGetElapsedTimef()));
	ofPushMatrix();
	glDepthMask(GL_TRUE);
	plane.draw();
	ofPopMatrix();
	bloom_shader_blur.end();
	ofPopMatrix();
	// put here for cool effect?
	//glDepthMask(GL_TRUE);












	// Colourful Shader
	colourful_shader.begin();
	colourful_shader.setUniformTexture("tex0", tex0, 1);
	colourful_shader.setUniform2f("texRes", glm::vec2(tex0.getWidth(), tex0.getHeight()));
	ofPushMatrix();
	ofRotateYDeg(-90);
	ofTranslate(-0.5*plane.getWidth(), 0, 0.5*plane.getWidth());
	plane.draw();
	ofPopMatrix();
	colourful_shader.end();
	//ofPopMatrix();

	cam.end();
}
