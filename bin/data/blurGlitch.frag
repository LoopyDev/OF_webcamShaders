
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
uniform float time;

void main()
{   
		//the direction of  blur
	//(1.0, 0.0) -> x-axis blur
	//(0.0, 1.0) -> y-axis blur
	float hstep = 1.0;
	float vstep = 0.0;
    // Flips image
    // vec2 newTexCoord = varyingtexcoord *-1 + 1;
    // newTexCoord.x *= -1;
    // newTexCoord.x += 1;
	if(dir.x == 1.0){
		
	}
    float radius = 70000.0*sin(time);
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
	vec2 blur = vec2(radius/texRes.y,radius/texRes.x); 
    


	//apply blurring, using a 9-tap filter with predefined gaussian weights
    
// 								
	// vec4 sumTemp_1 = 
    sum += texture(tex0, vec2(tc.x - 10.0*blur.x*hstep, tc.y - 10.0*blur.y*vstep)) * 0.000001;
	sum += texture(tex0, vec2(tc.x - 9.0*blur.x*hstep, tc.y - 9.0*blur.y*vstep)) * 0.00001;

    sum += texture(tex0, vec2(tc.x - 8.0*blur.x*hstep, tc.y - 8.0*blur.y*vstep)) * 0.000078;
	sum += texture(tex0, vec2(tc.x - 7.0*blur.x*hstep, tc.y - 7.0*blur.y*vstep)) * 0.000489;
	sum += texture(tex0, vec2(tc.x - 6.0*blur.x*hstep, tc.y - 6.0*blur.y*vstep)) * 0.002403;
	sum += texture(tex0, vec2(tc.x - 5.0*blur.x*hstep, tc.y - 5.0*blur.y*vstep)) * 0.009245;
    
    sum += texture(tex0, vec2(tc.x - 4.0*blur.x*hstep, tc.y - 4.0*blur.y*vstep)) * 0.027835;
	sum += texture(tex0, vec2(tc.x - 3.0*blur.x*hstep, tc.y - 3.0*blur.y*vstep)) * 0.065591;
	sum += texture(tex0, vec2(tc.x - 2.0*blur.x*hstep, tc.y - 2.0*blur.y*vstep)) * 0.120978;
	sum += texture(tex0, vec2(tc.x - 1.0*blur.x*hstep, tc.y - 1.0*blur.y*vstep)) * 0.174666;
	
    sum += texture(tex0, vec2(tc.x, tc.y)) * 0.197413;

	
	sum += texture(tex0, vec2(tc.x + 1.0*blur.x*hstep, tc.y + 1.0*blur.y*vstep)) * 0.174666;
	sum += texture(tex0, vec2(tc.x + 2.0*blur.x*hstep, tc.y + 2.0*blur.y*vstep)) * 0.120978;
	sum += texture(tex0, vec2(tc.x + 3.0*blur.x*hstep, tc.y + 3.0*blur.y*vstep)) * 0.065591;
	sum += texture(tex0, vec2(tc.x + 4.0*blur.x*hstep, tc.y + 4.0*blur.y*vstep)) * 0.027835;

	sum += texture(tex0, vec2(tc.x + 5.0*blur.x*hstep, tc.y + 5.0*blur.y*vstep)) * 0.009245;
	sum += texture(tex0, vec2(tc.x + 6.0*blur.x*hstep, tc.y + 6.0*blur.y*vstep)) * 0.002403;
	sum += texture(tex0, vec2(tc.x + 7.0*blur.x*hstep, tc.y + 7.0*blur.y*vstep)) * 0.000489;
	sum += texture(tex0, vec2(tc.x + 8.0*blur.x*hstep, tc.y + 8.0*blur.y*vstep)) * 0.000078;

	sum += texture(tex0, vec2(tc.x + 9.0*blur.x*hstep, tc.y + 9.0*blur.y*vstep)) * 0.00001;
	sum += texture(tex0, vec2(tc.x + 10.0*blur.x*hstep, tc.y + 10.0*blur.y*vstep)) * 0.000001;


	// sum.r *=1.5;
    // sum.b *= 2;
	float contrast = 2.0;
	vec4 originalCol = sum;
	vec4 finalCol = vec4(((originalCol.rgb-vec3(0.5))*contrast)+vec3(0.5),1.0);
	finalCol.b*=1.5;
    fragColor = clamp(finalCol, 0.05,1.0 );

}