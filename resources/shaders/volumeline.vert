struct app2vert
 {
      float4 startpos
      float4 endpos
      float4 color
      float4 param8
      float3 param9
 };

vertex_fragment vertex_main( app_vertex IN )
{
	vertex_fragment OUT;
  
 	 // Get OpenGL state matrices
  	float4x4 ModelView = glstate.matrix.modelview[0];
  	float4x4 ModelViewProj = glstate.matrix.mvp;

	posstart = mul(ModelViewProj, IN.startpos);
	posend = mul(ModelViewProj, IN.endpos);

	float2 startpos2d = posstart.xy / posstart.w;
	float2 endpos2d = posend.xy / posend.w;

	float2 linedir2d = normalize(startpos2d - endpos2d);

	posstart.xy = ((texcoef * IN.param8.x) * linedir2d.xy) + posstart.xy;

	linedir2d = IN.param9.x * linedir2d;
	posstart.x = posstart.x + linedir2d.y; // vertical x
	posstart.y = posstart.y - linedir2d.x; // vertical y
	OUT.hpos = posstart;
}
