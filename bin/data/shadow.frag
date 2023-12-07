
// fragment shader
#version 330 core
in vec4 vColor;

// UNIFORMS
//
// texture
uniform sampler2DRect tex0;
// texture size
uniform vec2 texRes;
in vec2 varyingtexcoord;
out vec4 fragColor;

uniform float timeSin;
uniform vec2 dir;

float kernel[7] = float[] (	0.098779,	0.09683,	0.091209,	0.082557,	0.071805,	0.060013,	0.048196);

void main()
{   
	
		 // Flips image
    // vec2 newTexCoord = varyingtexcoord *-1 + 1;
    // newTexCoord.x *= -1;
    // newTexCoord.x += 1;
    // float radius = 9000.0;
    //  * sin(time);
    // float radius = 4000.0;
    //this will be our RGBA sum
	vec4 sum = vec4(0.0);
	
	//our original texcoord for this fragment
	vec2 tc = varyingtexcoord;
    tc.y = tc.y *-1 + texRes.y;
	//the amount to blur, i.e. how far off center to sample from 
	//1.0 -> blur by one pixel
	//2.0 -> blur by two pixels, etc.
    
	//the direction of our blur
	//(1.0, 0.0) -> x-axis blur
	//(0.0, 1.0) -> y-axis blur
	float hstep = dir.x;
	float vstep = dir.y;
    // float hstep = 1.0;
    // float vstep = 0.0;
    
	//apply blurring, using a 9-tap filter with predefined gaussian weights
    
// 								
int stepNum = 10;



    vec2 tex_offset =vec2(1.0,1.0); // gets size of single texel
    vec4 result = texture(tex0, tc).rgba * kernel[0]; // current fragment's contribution
    if(hstep == 1.0)
    {
        for(int i = 1; i < 7; ++i)
        {
            result += texture(tex0, tc + vec2(tex_offset.x * i, 0.0)).rgba * kernel[i];
            result += texture(tex0, tc - vec2(tex_offset.x * i, 0.0)).rgba * kernel[i];
        }
    }
    else
    {
        for(int i = 1; i <  7; ++i)
        {
            result += texture(tex0, tc + vec2(0.0, tex_offset.y * i)).rgba * kernel[i];
            result += texture(tex0, tc - vec2(0.0, tex_offset.y * i)).rgba * kernel[i];
        }
    }

    result.rgb *= 0.5;
    result.a *= 0.8;
    fragColor = result;

}