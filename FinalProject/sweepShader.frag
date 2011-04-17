// this is the texture map data we can sample
uniform sampler2D textureMap, heightMap, normalMap;

// these are the texture and bump mapping settings we can toggle
uniform bool bumpMapEnabled, textureMapEnabled, phongEnabled;

// These varying values are interpolated over the surface
varying vec4 v;
varying vec3 t;
varying vec3 b;
varying vec3 n;
varying vec4 gColor;

void main()
{
	vec3 normal = vec3(texture2D(normalMap,gl_TexCoord[0].st));// @TODO: put in a correct normal here
    normal = (normal*2.0) - vec3(1.0,1.0,1.0);
    if (!bumpMapEnabled) {
        normal = n;
    }
    
    mat3 matrix = mat3(t, b, n);
    normal = normalize(matrix*normal);

    vec3 e = normalize(v).xyz; // in eye space, eye is at origin
    // light sources are in eye space; it is okay to assume directional light
    vec3 l = normalize(gl_LightSource[0].position.xyz);
    vec3 r = reflect(-l,normal); // reflect function assumes vectors are normalized

    

    // sample from a texture map
    //vec4 texcolor = texture2D(textureMap,gl_TexCoord[0].st);
    
    //vec2 texCoord = vec2(dot(normal, e), gl_TexCoord[0].st[1] * gl_TexCoord[0].st[0]);

    	vec2 texCoord = vec2(abs(dot(e, n)), 0.0);
    	vec4 texcolor = texture2D(textureMap,texCoord);
    
    if (!textureMapEnabled) {
        texcolor = vec4(1,1,1,1);
    }


    float p = 20.0;
    vec4 cr = texcolor;
    vec4 cl = gl_LightSource[0].diffuse;
    vec4 ca = vec4(.2,.2,.2,1.0);
    
    // the below is fine for a lighting equation
    vec4 color;
    color = cr * (ca + cl * max(0.0,dot(normal,l))) + 
                    cl * pow(max(0.0,dot(r,-e)),p);

    
    // set the output color to what we've computed
    gl_FragColor = color;
    if (!phongEnabled) {
    	gl_FragColor = gColor;
    }

   
}
