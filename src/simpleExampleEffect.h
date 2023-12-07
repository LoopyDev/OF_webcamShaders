#pragma once

#include "ofMain.h"

class simpleExampleEffect {

public:


	void setup(ofTexture &tex0);
	void update();
	void draw(ofTexture &tex0);

	// Camera
	ofCamera cam;
	// Plane
	ofPlanePrimitive plane;
	// Shaders & FBOs
	ofShader blurGlitch_shader;
	ofShader colourful_shader;
	ofShader bloom_thresthold_shader;
	ofShader bloom_shader_blur;
	ofShader shadow_shader_blur;
	ofShader shadow_thresthold_shader;

	ofFbo bloom_thresthold_fbo;
	ofFbo bloom_fbo_blur;
	ofFbo bloom_fbo_blur_vertical;
	ofFbo shadow_thresthold_fbo;
	ofFbo shadow_fbo_blur;
	ofFbo shadow_fbo_blur_vertical;
};
