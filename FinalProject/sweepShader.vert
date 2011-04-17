attribute vec3 tangent;
attribute vec3 bitangent;

// NOTE:
// varying variables are set by the vertex shader
// then interpolated by the harder 
// and the interpolated values are passed to the fragment shader
// so the corresponding varying vec4 v in the fragment shader
// will be the linearly interpolated position of the spot you're shading.
varying vec4 v;

// NOTE:
// we'll pass the TBN matrix down
// in order to do the lighting in eye space
// many people do it in tangent space instead, for efficiency
// but for the sake of exercise we'll do it all in eye space
varying vec3 t;
varying vec3 b;
varying vec3 n;
varying vec4 gColor; 

void main()
{
    // put everything varying in eye space
    v = gl_ModelViewMatrix * gl_Vertex;
    // @TODO: SET t,b,n appropriately
    // HINT: remember normals transform by the gl_NormalMatrix
	// t = normalize(vec3(gl_ModelViewMatrix* vec4(tangent, 0.0)));
	t = normalize(gl_NormalMatrix *tangent);
	b = normalize(gl_NormalMatrix *bitangent);
	n = normalize(gl_NormalMatrix * gl_Normal);
	
	
	vec3 normal = vec3(0,0,1);
	normal = normalize(mat3(t,b,n)*normal);
	vec4 texcolor = vec4(1,1,1,1);
	vec3 e = normalize(v).xyz; // in eye space, eye is at origin
    // light sources are in eye space; it is okay to assume directional light
    vec3 l = normalize(gl_LightSource[0].position.xyz);
    vec3 r = reflect(-l,normal); // reflect function assumes vectors are normalized
    
    // setting up your light parameters in the shader is fine
    // don't worry about matching the opengl lighting settings
    // the fixed function uses the blinn-phong half-angle formula anyway
    // while we've asked you to use the standard phong model

    float p = 20.0;
    vec4 cr = texcolor;
    vec4 cl = gl_LightSource[0].diffuse;
    vec4 ca = vec4(.2,.2,.2,1.0);
    
    // the below is fine for a lighting equation
    gColor = cr * (ca + cl * max(0.0,dot(normal,l))) + 
                    cl * pow(max(0.0,dot(r,-e)),p);

	
	
	//b = normalize(vec3(gl_ModelViewMatrix* vec4(bitangent, 0.0)));
	
	//t = normalize(gl_NormalMatrix * tangent);
	//n = normalize(gl_NormalMatrix * gl_Normal);
	//b = normalize(gl_NormalMatrix * bitangent);
	//t = gl_ModelViewMatrix * gl_Vertex;
	
	//b = t * n;
	// pass down the texture coords
	gl_TexCoord[0] = gl_MultiTexCoord0;
    
    // position by the standard transform
    // as this shader doesn't change geometry
	gl_Position = ftransform();
}