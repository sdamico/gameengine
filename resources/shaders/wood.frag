uniform float GrainSizeRecip;
uniform vec3  DarkColor;
uniform vec3  spread;

varying float lightIntensity; 
varying vec3 Position;

void main (void)
{
    
    vec3 location = Position;
    vec3 floorvec = vec3(floor(10.0 * Position.x), 0.0, floor(10.0 * Position.z));
    vec3 noise = Position * 10.0 - floorvec - 0.5;
    noise *= noise;
    location += noise * 0.12;

    
    float dist = location.x * location.x + location.z * location.z;
    float grain = dist * GrainSizeRecip;

   
    float brightness = fract(grain);
    if (brightness > 0.5) 
        brightness = (1.0 - brightness);
    vec3 color = DarkColor + brightness * spread;
    
    brightness = fract(grain * 7.0);    
    if (brightness > 0.5) 
        brightness = 1.0 - brightness;
    color -= brightness * spread;

    
    brightness = fract(grain * 47.0) * 0.60;
    float line = fract(Position.z + Position.x);
    float snap = floor(line * 20.0) * (1.0/20.0);
    if (line < snap + 0.006)
        color -= brightness * spread;

    
    color = clamp(color * lightIntensity, 0.0, 1.0); 

    gl_FragColor = vec4(color, 1.0);
}
