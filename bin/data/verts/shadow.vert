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

void main()
{


    varyingtexcoord = vec2(texcoord.x, texcoord.y);

    gl_Position = modelViewProjectionMatrix * position;





















    //             vec4 posModelSpace = position;

    // vec4 posWorldSpace = modelMatrix * posModelSpace;

    // vec4 posViewSpace = viewMatrix * posWorldSpace;

    //     // posViewSpace.y += 0.5 * sin(freqTime * time + freqSpace * posViewSpace.y);
    //     posViewSpace += 0.5* map(sin(snoise(vec4(position.x,position.y,position.z,time)) * normalize(normal).x),-1,1,0,2);
    //     posViewSpace += 0.5 * map(sin(snoise(vec4(position.x,position.y,position.z,time)) * normalize(normal).y),-1,1,0,1);
    //     posViewSpace += 0.5 * map(sin(snoise(vec4(position.x,position.y,position.z,time)) * normalize(normal).z),-1,1,0,2);
    // vec4 posProjectionSpace = projectionMatrix * posViewSpace;
    // posProjectionSpace /= posProjectionSpace.w;



    // vec4 normMatrix = modelViewProjectionMatrix * position;
    // normMatrix = normMatrix / normMatrix.w;
    // // float mouseDist = distance(vec2(mouseX,mouseY),vec2(normMatrix.x, normMatrix.y));
    // // if(mouseDist > 0.2){
    // //     v_color = vec4(0,1,1,1);
    // //     gl_Position = modelViewProjectionMatrix * position;
    // // }
    // // else{
    //     gl_Position = posProjectionSpace;

    // // }








	// mat4 normalMatrix =  transpose(inverse(modelViewMatrix));
    // v_viewSpaceNormal = normalize((normalMatrix * normal).xyz);
	// v_viewSpacePosition = (modelViewMatrix * position).xyz;
    // v_texcoord = (textureMatrix*vec4(texcoord.x,texcoord.y,0,1)).xy;

}