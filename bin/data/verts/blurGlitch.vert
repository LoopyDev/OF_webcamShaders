#version 330 core

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

uniform float time;
uniform vec2 resolution;

in vec4 position;
in vec4 color;
in vec4 normal;
in vec2 texcoord;
// this is the end of the default functionality

// this is something we're creating for this shader
out vec2 varyingtexcoord;
out vec4 vColor;
out vec2 v_texcoord;
out vec3 v_viewSpaceNormal;
out vec3 v_viewSpacePosition;

// this is coming from our C++ code
uniform vec2 texRes;

uniform sampler2DRect tex0;

// out vec2 left_coord;
// out vec2 right_coord;
// out vec2 above_coord;
// out vec2 below_coord;

// out vec2 lefta_coord;
// out vec2 righta_coord;
// out vec2 leftb_coord;
// out vec2 rightb_coord;



void main()
{
        // varyingtexcoord = vec2(texcoord.x *-1 + texRes.x,texcoord.y);
        varyingtexcoord = texcoord *-1 + texRes;

    // varyingtexcoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
}