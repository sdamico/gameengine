// transl output by Cg compiler
// cgc version 1.5.0014, build date Sep 18 2006 21:55:12
// command line args: -profile glslv
// source file: volumeline_v.cgv
//vendor NVIDIA Corporation
//version 1.5.0.14
//profile glslv
//program main
//semantic glstate : STATE
//semantic IN
//var float4 glstate.material.ambient : STATE.MATERIAL.AMBIENT :  : -1 : 0
//var float4 glstate.material.diffuse : STATE.MATERIAL.DIFFUSE :  : -1 : 0
//var float4 glstate.material.specular : STATE.MATERIAL.SPECULAR :  : -1 : 0
//var float4 glstate.material.emission : STATE.MATERIAL.EMISSION :  : -1 : 0
//var float4 glstate.material.shininess : STATE.MATERIAL.SHININESS :  : -1 : 0
//var float4 glstate.material.front.ambient : STATE.MATERIAL.FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.material.front.diffuse : STATE.MATERIAL.FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.material.front.specular : STATE.MATERIAL.FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.material.front.emission : STATE.MATERIAL.FRONT.EMISSION :  : -1 : 0
//var float4 glstate.material.front.shininess : STATE.MATERIAL.FRONT.SHININESS :  : -1 : 0
//var float4 glstate.material.back.ambient : STATE.MATERIAL.BACK.AMBIENT :  : -1 : 0
//var float4 glstate.material.back.diffuse : STATE.MATERIAL.BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.material.back.specular : STATE.MATERIAL.BACK.SPECULAR :  : -1 : 0
//var float4 glstate.material.back.emission : STATE.MATERIAL.BACK.EMISSION :  : -1 : 0
//var float4 glstate.material.back.shininess : STATE.MATERIAL.BACK.SHININESS :  : -1 : 0
//var float4 glstate.light[0].ambient : STATE.LIGHT[0].AMBIENT :  : -1 : 0
//var float4 glstate.light[0].diffuse : STATE.LIGHT[0].DIFFUSE :  : -1 : 0
//var float4 glstate.light[0].specular : STATE.LIGHT[0].SPECULAR :  : -1 : 0
//var float4 glstate.light[0].position : STATE.LIGHT[0].POSITION :  : -1 : 0
//var float4 glstate.light[0].attenuation : STATE.LIGHT[0].ATTENUATION :  : -1 : 0
//var float4 glstate.light[0].spot.direction : STATE.LIGHT[0].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[0].half : STATE.LIGHT[0].HALF :  : -1 : 0
//var float4 glstate.light[1].ambient : STATE.LIGHT[1].AMBIENT :  : -1 : 0
//var float4 glstate.light[1].diffuse : STATE.LIGHT[1].DIFFUSE :  : -1 : 0
//var float4 glstate.light[1].specular : STATE.LIGHT[1].SPECULAR :  : -1 : 0
//var float4 glstate.light[1].position : STATE.LIGHT[1].POSITION :  : -1 : 0
//var float4 glstate.light[1].attenuation : STATE.LIGHT[1].ATTENUATION :  : -1 : 0
//var float4 glstate.light[1].spot.direction : STATE.LIGHT[1].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[1].half : STATE.LIGHT[1].HALF :  : -1 : 0
//var float4 glstate.light[2].ambient : STATE.LIGHT[2].AMBIENT :  : -1 : 0
//var float4 glstate.light[2].diffuse : STATE.LIGHT[2].DIFFUSE :  : -1 : 0
//var float4 glstate.light[2].specular : STATE.LIGHT[2].SPECULAR :  : -1 : 0
//var float4 glstate.light[2].position : STATE.LIGHT[2].POSITION :  : -1 : 0
//var float4 glstate.light[2].attenuation : STATE.LIGHT[2].ATTENUATION :  : -1 : 0
//var float4 glstate.light[2].spot.direction : STATE.LIGHT[2].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[2].half : STATE.LIGHT[2].HALF :  : -1 : 0
//var float4 glstate.light[3].ambient : STATE.LIGHT[3].AMBIENT :  : -1 : 0
//var float4 glstate.light[3].diffuse : STATE.LIGHT[3].DIFFUSE :  : -1 : 0
//var float4 glstate.light[3].specular : STATE.LIGHT[3].SPECULAR :  : -1 : 0
//var float4 glstate.light[3].position : STATE.LIGHT[3].POSITION :  : -1 : 0
//var float4 glstate.light[3].attenuation : STATE.LIGHT[3].ATTENUATION :  : -1 : 0
//var float4 glstate.light[3].spot.direction : STATE.LIGHT[3].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[3].half : STATE.LIGHT[3].HALF :  : -1 : 0
//var float4 glstate.light[4].ambient : STATE.LIGHT[4].AMBIENT :  : -1 : 0
//var float4 glstate.light[4].diffuse : STATE.LIGHT[4].DIFFUSE :  : -1 : 0
//var float4 glstate.light[4].specular : STATE.LIGHT[4].SPECULAR :  : -1 : 0
//var float4 glstate.light[4].position : STATE.LIGHT[4].POSITION :  : -1 : 0
//var float4 glstate.light[4].attenuation : STATE.LIGHT[4].ATTENUATION :  : -1 : 0
//var float4 glstate.light[4].spot.direction : STATE.LIGHT[4].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[4].half : STATE.LIGHT[4].HALF :  : -1 : 0
//var float4 glstate.light[5].ambient : STATE.LIGHT[5].AMBIENT :  : -1 : 0
//var float4 glstate.light[5].diffuse : STATE.LIGHT[5].DIFFUSE :  : -1 : 0
//var float4 glstate.light[5].specular : STATE.LIGHT[5].SPECULAR :  : -1 : 0
//var float4 glstate.light[5].position : STATE.LIGHT[5].POSITION :  : -1 : 0
//var float4 glstate.light[5].attenuation : STATE.LIGHT[5].ATTENUATION :  : -1 : 0
//var float4 glstate.light[5].spot.direction : STATE.LIGHT[5].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[5].half : STATE.LIGHT[5].HALF :  : -1 : 0
//var float4 glstate.light[6].ambient : STATE.LIGHT[6].AMBIENT :  : -1 : 0
//var float4 glstate.light[6].diffuse : STATE.LIGHT[6].DIFFUSE :  : -1 : 0
//var float4 glstate.light[6].specular : STATE.LIGHT[6].SPECULAR :  : -1 : 0
//var float4 glstate.light[6].position : STATE.LIGHT[6].POSITION :  : -1 : 0
//var float4 glstate.light[6].attenuation : STATE.LIGHT[6].ATTENUATION :  : -1 : 0
//var float4 glstate.light[6].spot.direction : STATE.LIGHT[6].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[6].half : STATE.LIGHT[6].HALF :  : -1 : 0
//var float4 glstate.light[7].ambient : STATE.LIGHT[7].AMBIENT :  : -1 : 0
//var float4 glstate.light[7].diffuse : STATE.LIGHT[7].DIFFUSE :  : -1 : 0
//var float4 glstate.light[7].specular : STATE.LIGHT[7].SPECULAR :  : -1 : 0
//var float4 glstate.light[7].position : STATE.LIGHT[7].POSITION :  : -1 : 0
//var float4 glstate.light[7].attenuation : STATE.LIGHT[7].ATTENUATION :  : -1 : 0
//var float4 glstate.light[7].spot.direction : STATE.LIGHT[7].SPOT.DIRECTION :  : -1 : 0
//var float4 glstate.light[7].half : STATE.LIGHT[7].HALF :  : -1 : 0
//var float4 glstate.lightmodel.ambient : STATE.LIGHTMODEL.AMBIENT :  : -1 : 0
//var float4 glstate.lightmodel.scenecolor : STATE.LIGHTMODEL.SCENECOLOR :  : -1 : 0
//var float4 glstate.lightmodel.front.scenecolor : STATE.LIGHTMODEL.FRONT.SCENECOLOR :  : -1 : 0
//var float4 glstate.lightmodel.back.scenecolor : STATE.LIGHTMODEL.BACK.SCENECOLOR :  : -1 : 0
//var float4 glstate.lightprod[0].ambient : STATE.LIGHTPROD[0].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[0].diffuse : STATE.LIGHTPROD[0].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[0].specular : STATE.LIGHTPROD[0].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[0].front.ambient : STATE.LIGHTPROD[0].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[0].front.diffuse : STATE.LIGHTPROD[0].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[0].front.specular : STATE.LIGHTPROD[0].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[0].back.ambient : STATE.LIGHTPROD[0].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[0].back.diffuse : STATE.LIGHTPROD[0].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[0].back.specular : STATE.LIGHTPROD[0].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[1].ambient : STATE.LIGHTPROD[1].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[1].diffuse : STATE.LIGHTPROD[1].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[1].specular : STATE.LIGHTPROD[1].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[1].front.ambient : STATE.LIGHTPROD[1].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[1].front.diffuse : STATE.LIGHTPROD[1].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[1].front.specular : STATE.LIGHTPROD[1].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[1].back.ambient : STATE.LIGHTPROD[1].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[1].back.diffuse : STATE.LIGHTPROD[1].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[1].back.specular : STATE.LIGHTPROD[1].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[2].ambient : STATE.LIGHTPROD[2].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[2].diffuse : STATE.LIGHTPROD[2].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[2].specular : STATE.LIGHTPROD[2].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[2].front.ambient : STATE.LIGHTPROD[2].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[2].front.diffuse : STATE.LIGHTPROD[2].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[2].front.specular : STATE.LIGHTPROD[2].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[2].back.ambient : STATE.LIGHTPROD[2].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[2].back.diffuse : STATE.LIGHTPROD[2].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[2].back.specular : STATE.LIGHTPROD[2].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[3].ambient : STATE.LIGHTPROD[3].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[3].diffuse : STATE.LIGHTPROD[3].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[3].specular : STATE.LIGHTPROD[3].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[3].front.ambient : STATE.LIGHTPROD[3].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[3].front.diffuse : STATE.LIGHTPROD[3].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[3].front.specular : STATE.LIGHTPROD[3].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[3].back.ambient : STATE.LIGHTPROD[3].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[3].back.diffuse : STATE.LIGHTPROD[3].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[3].back.specular : STATE.LIGHTPROD[3].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[4].ambient : STATE.LIGHTPROD[4].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[4].diffuse : STATE.LIGHTPROD[4].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[4].specular : STATE.LIGHTPROD[4].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[4].front.ambient : STATE.LIGHTPROD[4].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[4].front.diffuse : STATE.LIGHTPROD[4].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[4].front.specular : STATE.LIGHTPROD[4].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[4].back.ambient : STATE.LIGHTPROD[4].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[4].back.diffuse : STATE.LIGHTPROD[4].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[4].back.specular : STATE.LIGHTPROD[4].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[5].ambient : STATE.LIGHTPROD[5].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[5].diffuse : STATE.LIGHTPROD[5].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[5].specular : STATE.LIGHTPROD[5].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[5].front.ambient : STATE.LIGHTPROD[5].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[5].front.diffuse : STATE.LIGHTPROD[5].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[5].front.specular : STATE.LIGHTPROD[5].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[5].back.ambient : STATE.LIGHTPROD[5].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[5].back.diffuse : STATE.LIGHTPROD[5].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[5].back.specular : STATE.LIGHTPROD[5].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[6].ambient : STATE.LIGHTPROD[6].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[6].diffuse : STATE.LIGHTPROD[6].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[6].specular : STATE.LIGHTPROD[6].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[6].front.ambient : STATE.LIGHTPROD[6].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[6].front.diffuse : STATE.LIGHTPROD[6].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[6].front.specular : STATE.LIGHTPROD[6].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[6].back.ambient : STATE.LIGHTPROD[6].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[6].back.diffuse : STATE.LIGHTPROD[6].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[6].back.specular : STATE.LIGHTPROD[6].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[7].ambient : STATE.LIGHTPROD[7].AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[7].diffuse : STATE.LIGHTPROD[7].DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[7].specular : STATE.LIGHTPROD[7].SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[7].front.ambient : STATE.LIGHTPROD[7].FRONT.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[7].front.diffuse : STATE.LIGHTPROD[7].FRONT.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[7].front.specular : STATE.LIGHTPROD[7].FRONT.SPECULAR :  : -1 : 0
//var float4 glstate.lightprod[7].back.ambient : STATE.LIGHTPROD[7].BACK.AMBIENT :  : -1 : 0
//var float4 glstate.lightprod[7].back.diffuse : STATE.LIGHTPROD[7].BACK.DIFFUSE :  : -1 : 0
//var float4 glstate.lightprod[7].back.specular : STATE.LIGHTPROD[7].BACK.SPECULAR :  : -1 : 0
//var float4 glstate.texgen[0].eye.s : STATE.TEXGEN[0].EYE.S :  : -1 : 0
//var float4 glstate.texgen[0].eye.t : STATE.TEXGEN[0].EYE.T :  : -1 : 0
//var float4 glstate.texgen[0].eye.r : STATE.TEXGEN[0].EYE.R :  : -1 : 0
//var float4 glstate.texgen[0].eye.q : STATE.TEXGEN[0].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[0].object.s : STATE.TEXGEN[0].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[0].object.t : STATE.TEXGEN[0].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[0].object.r : STATE.TEXGEN[0].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[0].object.q : STATE.TEXGEN[0].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[1].eye.s : STATE.TEXGEN[1].EYE.S :  : -1 : 0
//var float4 glstate.texgen[1].eye.t : STATE.TEXGEN[1].EYE.T :  : -1 : 0
//var float4 glstate.texgen[1].eye.r : STATE.TEXGEN[1].EYE.R :  : -1 : 0
//var float4 glstate.texgen[1].eye.q : STATE.TEXGEN[1].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[1].object.s : STATE.TEXGEN[1].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[1].object.t : STATE.TEXGEN[1].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[1].object.r : STATE.TEXGEN[1].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[1].object.q : STATE.TEXGEN[1].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[2].eye.s : STATE.TEXGEN[2].EYE.S :  : -1 : 0
//var float4 glstate.texgen[2].eye.t : STATE.TEXGEN[2].EYE.T :  : -1 : 0
//var float4 glstate.texgen[2].eye.r : STATE.TEXGEN[2].EYE.R :  : -1 : 0
//var float4 glstate.texgen[2].eye.q : STATE.TEXGEN[2].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[2].object.s : STATE.TEXGEN[2].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[2].object.t : STATE.TEXGEN[2].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[2].object.r : STATE.TEXGEN[2].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[2].object.q : STATE.TEXGEN[2].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[3].eye.s : STATE.TEXGEN[3].EYE.S :  : -1 : 0
//var float4 glstate.texgen[3].eye.t : STATE.TEXGEN[3].EYE.T :  : -1 : 0
//var float4 glstate.texgen[3].eye.r : STATE.TEXGEN[3].EYE.R :  : -1 : 0
//var float4 glstate.texgen[3].eye.q : STATE.TEXGEN[3].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[3].object.s : STATE.TEXGEN[3].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[3].object.t : STATE.TEXGEN[3].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[3].object.r : STATE.TEXGEN[3].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[3].object.q : STATE.TEXGEN[3].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[4].eye.s : STATE.TEXGEN[4].EYE.S :  : -1 : 0
//var float4 glstate.texgen[4].eye.t : STATE.TEXGEN[4].EYE.T :  : -1 : 0
//var float4 glstate.texgen[4].eye.r : STATE.TEXGEN[4].EYE.R :  : -1 : 0
//var float4 glstate.texgen[4].eye.q : STATE.TEXGEN[4].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[4].object.s : STATE.TEXGEN[4].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[4].object.t : STATE.TEXGEN[4].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[4].object.r : STATE.TEXGEN[4].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[4].object.q : STATE.TEXGEN[4].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[5].eye.s : STATE.TEXGEN[5].EYE.S :  : -1 : 0
//var float4 glstate.texgen[5].eye.t : STATE.TEXGEN[5].EYE.T :  : -1 : 0
//var float4 glstate.texgen[5].eye.r : STATE.TEXGEN[5].EYE.R :  : -1 : 0
//var float4 glstate.texgen[5].eye.q : STATE.TEXGEN[5].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[5].object.s : STATE.TEXGEN[5].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[5].object.t : STATE.TEXGEN[5].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[5].object.r : STATE.TEXGEN[5].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[5].object.q : STATE.TEXGEN[5].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[6].eye.s : STATE.TEXGEN[6].EYE.S :  : -1 : 0
//var float4 glstate.texgen[6].eye.t : STATE.TEXGEN[6].EYE.T :  : -1 : 0
//var float4 glstate.texgen[6].eye.r : STATE.TEXGEN[6].EYE.R :  : -1 : 0
//var float4 glstate.texgen[6].eye.q : STATE.TEXGEN[6].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[6].object.s : STATE.TEXGEN[6].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[6].object.t : STATE.TEXGEN[6].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[6].object.r : STATE.TEXGEN[6].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[6].object.q : STATE.TEXGEN[6].OBJECT.Q :  : -1 : 0
//var float4 glstate.texgen[7].eye.s : STATE.TEXGEN[7].EYE.S :  : -1 : 0
//var float4 glstate.texgen[7].eye.t : STATE.TEXGEN[7].EYE.T :  : -1 : 0
//var float4 glstate.texgen[7].eye.r : STATE.TEXGEN[7].EYE.R :  : -1 : 0
//var float4 glstate.texgen[7].eye.q : STATE.TEXGEN[7].EYE.Q :  : -1 : 0
//var float4 glstate.texgen[7].object.s : STATE.TEXGEN[7].OBJECT.S :  : -1 : 0
//var float4 glstate.texgen[7].object.t : STATE.TEXGEN[7].OBJECT.T :  : -1 : 0
//var float4 glstate.texgen[7].object.r : STATE.TEXGEN[7].OBJECT.R :  : -1 : 0
//var float4 glstate.texgen[7].object.q : STATE.TEXGEN[7].OBJECT.Q :  : -1 : 0
//var float4 glstate.fog.color : STATE.FOG.COLOR :  : -1 : 0
//var float4 glstate.fog.params : STATE.FOG.PARAMS :  : -1 : 0
//var float4 glstate.clip[0].plane : STATE.CLIP[0].PLANE :  : -1 : 0
//var float4 glstate.clip[1].plane : STATE.CLIP[1].PLANE :  : -1 : 0
//var float4 glstate.clip[2].plane : STATE.CLIP[2].PLANE :  : -1 : 0
//var float4 glstate.clip[3].plane : STATE.CLIP[3].PLANE :  : -1 : 0
//var float4 glstate.clip[4].plane : STATE.CLIP[4].PLANE :  : -1 : 0
//var float4 glstate.clip[5].plane : STATE.CLIP[5].PLANE :  : -1 : 0
//var float4 glstate.clip[6].plane : STATE.CLIP[6].PLANE :  : -1 : 0
//var float4 glstate.clip[7].plane : STATE.CLIP[7].PLANE :  : -1 : 0
//var float glstate.point.size : STATE.POINT.SIZE :  : -1 : 0
//var float glstate.point.attenuation : STATE.POINT.ATTENUATION :  : -1 : 0
//var float4x4 glstate.matrix.modelview[0] : STATE.MATRIX.MODELVIEW[0] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[1] : STATE.MATRIX.MODELVIEW[1] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[2] : STATE.MATRIX.MODELVIEW[2] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[3] : STATE.MATRIX.MODELVIEW[3] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[4] : STATE.MATRIX.MODELVIEW[4] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[5] : STATE.MATRIX.MODELVIEW[5] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[6] : STATE.MATRIX.MODELVIEW[6] : , 4 : -1 : 0
//var float4x4 glstate.matrix.modelview[7] : STATE.MATRIX.MODELVIEW[7] : , 4 : -1 : 0
//var float4x4 glstate.matrix.projection : STATE.MATRIX.PROJECTION : , 4 : -1 : 0
//var float4x4 glstate.matrix.mvp : STATE.MATRIX.MVP : glstate.matrix.mvp[0], 4 : -1 : 1
//var float4x4 glstate.matrix.texture[0] : STATE.MATRIX.TEXTURE[0] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[1] : STATE.MATRIX.TEXTURE[1] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[2] : STATE.MATRIX.TEXTURE[2] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[3] : STATE.MATRIX.TEXTURE[3] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[4] : STATE.MATRIX.TEXTURE[4] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[5] : STATE.MATRIX.TEXTURE[5] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[6] : STATE.MATRIX.TEXTURE[6] : , 4 : -1 : 0
//var float4x4 glstate.matrix.texture[7] : STATE.MATRIX.TEXTURE[7] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[0] : STATE.MATRIX.PALETTE[0] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[1] : STATE.MATRIX.PALETTE[1] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[2] : STATE.MATRIX.PALETTE[2] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[3] : STATE.MATRIX.PALETTE[3] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[4] : STATE.MATRIX.PALETTE[4] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[5] : STATE.MATRIX.PALETTE[5] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[6] : STATE.MATRIX.PALETTE[6] : , 4 : -1 : 0
//var float4x4 glstate.matrix.palette[7] : STATE.MATRIX.PALETTE[7] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[0] : STATE.MATRIX.PROGRAM[0] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[1] : STATE.MATRIX.PROGRAM[1] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[2] : STATE.MATRIX.PROGRAM[2] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[3] : STATE.MATRIX.PROGRAM[3] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[4] : STATE.MATRIX.PROGRAM[4] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[5] : STATE.MATRIX.PROGRAM[5] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[6] : STATE.MATRIX.PROGRAM[6] : , 4 : -1 : 0
//var float4x4 glstate.matrix.program[7] : STATE.MATRIX.PROGRAM[7] : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[0] : STATE.MATRIX.MODELVIEW[0].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[1] : STATE.MATRIX.MODELVIEW[1].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[2] : STATE.MATRIX.MODELVIEW[2].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[3] : STATE.MATRIX.MODELVIEW[3].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[4] : STATE.MATRIX.MODELVIEW[4].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[5] : STATE.MATRIX.MODELVIEW[5].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[6] : STATE.MATRIX.MODELVIEW[6].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.modelview[7] : STATE.MATRIX.MODELVIEW[7].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.projection : STATE.MATRIX.PROJECTION.INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.mvp : STATE.MATRIX.MVP.INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[0] : STATE.MATRIX.TEXTURE[0].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[1] : STATE.MATRIX.TEXTURE[1].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[2] : STATE.MATRIX.TEXTURE[2].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[3] : STATE.MATRIX.TEXTURE[3].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[4] : STATE.MATRIX.TEXTURE[4].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[5] : STATE.MATRIX.TEXTURE[5].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[6] : STATE.MATRIX.TEXTURE[6].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.texture[7] : STATE.MATRIX.TEXTURE[7].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[0] : STATE.MATRIX.PALETTE[0].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[1] : STATE.MATRIX.PALETTE[1].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[2] : STATE.MATRIX.PALETTE[2].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[3] : STATE.MATRIX.PALETTE[3].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[4] : STATE.MATRIX.PALETTE[4].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[5] : STATE.MATRIX.PALETTE[5].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[6] : STATE.MATRIX.PALETTE[6].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.palette[7] : STATE.MATRIX.PALETTE[7].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[0] : STATE.MATRIX.PROGRAM[0].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[1] : STATE.MATRIX.PROGRAM[1].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[2] : STATE.MATRIX.PROGRAM[2].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[3] : STATE.MATRIX.PROGRAM[3].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[4] : STATE.MATRIX.PROGRAM[4].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[5] : STATE.MATRIX.PROGRAM[5].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[6] : STATE.MATRIX.PROGRAM[6].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.inverse.program[7] : STATE.MATRIX.PROGRAM[7].INVERSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[0] : STATE.MATRIX.MODELVIEW[0].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[1] : STATE.MATRIX.MODELVIEW[1].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[2] : STATE.MATRIX.MODELVIEW[2].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[3] : STATE.MATRIX.MODELVIEW[3].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[4] : STATE.MATRIX.MODELVIEW[4].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[5] : STATE.MATRIX.MODELVIEW[5].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[6] : STATE.MATRIX.MODELVIEW[6].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.modelview[7] : STATE.MATRIX.MODELVIEW[7].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.projection : STATE.MATRIX.PROJECTION.TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.mvp : STATE.MATRIX.MVP.TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[0] : STATE.MATRIX.TEXTURE[0].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[1] : STATE.MATRIX.TEXTURE[1].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[2] : STATE.MATRIX.TEXTURE[2].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[3] : STATE.MATRIX.TEXTURE[3].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[4] : STATE.MATRIX.TEXTURE[4].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[5] : STATE.MATRIX.TEXTURE[5].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[6] : STATE.MATRIX.TEXTURE[6].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.texture[7] : STATE.MATRIX.TEXTURE[7].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[0] : STATE.MATRIX.PALETTE[0].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[1] : STATE.MATRIX.PALETTE[1].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[2] : STATE.MATRIX.PALETTE[2].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[3] : STATE.MATRIX.PALETTE[3].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[4] : STATE.MATRIX.PALETTE[4].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[5] : STATE.MATRIX.PALETTE[5].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[6] : STATE.MATRIX.PALETTE[6].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.palette[7] : STATE.MATRIX.PALETTE[7].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[0] : STATE.MATRIX.PROGRAM[0].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[1] : STATE.MATRIX.PROGRAM[1].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[2] : STATE.MATRIX.PROGRAM[2].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[3] : STATE.MATRIX.PROGRAM[3].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[4] : STATE.MATRIX.PROGRAM[4].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[5] : STATE.MATRIX.PROGRAM[5].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[6] : STATE.MATRIX.PROGRAM[6].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.transpose.program[7] : STATE.MATRIX.PROGRAM[7].TRANSPOSE : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[0] : STATE.MATRIX.MODELVIEW[0].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[1] : STATE.MATRIX.MODELVIEW[1].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[2] : STATE.MATRIX.MODELVIEW[2].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[3] : STATE.MATRIX.MODELVIEW[3].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[4] : STATE.MATRIX.MODELVIEW[4].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[5] : STATE.MATRIX.MODELVIEW[5].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[6] : STATE.MATRIX.MODELVIEW[6].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.modelview[7] : STATE.MATRIX.MODELVIEW[7].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.projection : STATE.MATRIX.PROJECTION.INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.mvp : STATE.MATRIX.MVP.INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[0] : STATE.MATRIX.TEXTURE[0].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[1] : STATE.MATRIX.TEXTURE[1].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[2] : STATE.MATRIX.TEXTURE[2].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[3] : STATE.MATRIX.TEXTURE[3].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[4] : STATE.MATRIX.TEXTURE[4].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[5] : STATE.MATRIX.TEXTURE[5].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[6] : STATE.MATRIX.TEXTURE[6].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.texture[7] : STATE.MATRIX.TEXTURE[7].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[0] : STATE.MATRIX.PALETTE[0].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[1] : STATE.MATRIX.PALETTE[1].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[2] : STATE.MATRIX.PALETTE[2].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[3] : STATE.MATRIX.PALETTE[3].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[4] : STATE.MATRIX.PALETTE[4].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[5] : STATE.MATRIX.PALETTE[5].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[6] : STATE.MATRIX.PALETTE[6].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.palette[7] : STATE.MATRIX.PALETTE[7].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[0] : STATE.MATRIX.PROGRAM[0].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[1] : STATE.MATRIX.PROGRAM[1].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[2] : STATE.MATRIX.PROGRAM[2].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[3] : STATE.MATRIX.PROGRAM[3].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[4] : STATE.MATRIX.PROGRAM[4].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[5] : STATE.MATRIX.PROGRAM[5].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[6] : STATE.MATRIX.PROGRAM[6].INVTRANS : , 4 : -1 : 0
//var float4x4 glstate.matrix.invtrans.program[7] : STATE.MATRIX.PROGRAM[7].INVTRANS : , 4 : -1 : 0
//var float4 IN.startpos : POSITION :  : -1 : 0
//var float4 IN.endpos : PSIZE : pend_s2_IN.pend_endpos : -1 : 0
//var float4 IN.color : DIFFUSE :  : -1 : 0
//var float4 IN.param8 : TEXCOORD0 : pend_s2_IN.pend_param8 : -1 : 0
//var float3 IN.param9 : TEXCOORD1 : pend_s2_IN.pend_param9 : -1 : 0
//var float4 IN.startpos : $vin.POSITION : POSITION : 0 : 1
//var float4 IN.endpos : $vin.PSIZE :  : 0 : 0
//var float4 IN.color : $vin.DIFFUSE :  : 0 : 0
//var float4 IN.param8 : $vin.TEXCOORD0 : TEXCOORD0 : 0 : 1
//var float3 IN.param9 : $vin.TEXCOORD1 : TEXCOORD1 : 0 : 1
//var float4 main.startpos : $vout.POSITION : POSITION : -1 : 1
//var float4 main.endpos : $vout.PSIZE : PSIZE : -1 : 1
//var float4 main.color : $vout.DIFFUSE :  : -1 : 0
//var float4 main.param8 : $vout.TEXCOORD0 : TEXCOORD0 : -1 : 1
//var float3 main.param9 : $vout.TEXCOORD1 : TEXCOORD1 : -1 : 1

struct app2vert {
    vec4 pend_startpos;
    vec4 pend_endpos;
    vec4 pend_color;
    vec4 pend_param8;
    vec3 pend_param9;
};

vec4 dash1_pend_s3_r_0001;
vec4 dash1_pend_s3_r_0003;
vec3 cash0_pend_s3__temp0004;
vec3 dash1_pend_s3_v_0005;
vec3 cash0_pend_s3__temp0006;
float dash1_pend_s3_a_0011;
vec2 cash0_pend_s3__temp0012;
vec2 dash1_pend_s3_v_0013;
float dash1_pend_s3_x_0033;
float dash1_pend_s3_x_0037;
float dash1_pend_s3_x_0041;

 // main procedure, the original name was main
void main()
{

    app2vert pend_s4_IN;
    app2vert pend_s4_OUT;
    vec4 pend_s4_posstart;
    vec3 pend_s4_lineoffset;
    float pend_s4_texcoef;
    vec2 pend_s4_startpos2d;
    vec2 pend_s4_endpos2d;
    vec2 pend_s4_linedir2d;

    dash1_pend_s3_r_0001.x = dot(pend_s3_glstate.pend_matrix.pend_mvp[0], gl_Vertex);
    dash1_pend_s3_r_0001.y = dot(pend_s3_glstate.pend_matrix.pend_mvp[1], gl_Vertex);
    dash1_pend_s3_r_0001.z = dot(pend_s3_glstate.pend_matrix.pend_mvp[2], gl_Vertex);
    dash1_pend_s3_r_0001.w = dot(pend_s3_glstate.pend_matrix.pend_mvp[3], gl_Vertex);
    pend_s4_posstart = dash1_pend_s3_r_0001;
    dash1_pend_s3_r_0003.x = dot(pend_s3_glstate.pend_matrix.pend_mvp[0], pend_s4_IN.pend_endpos);
    dash1_pend_s3_r_0003.y = dot(pend_s3_glstate.pend_matrix.pend_mvp[1], pend_s4_IN.pend_endpos);
    dash1_pend_s3_r_0003.z = dot(pend_s3_glstate.pend_matrix.pend_mvp[2], pend_s4_IN.pend_endpos);
    dash1_pend_s3_r_0003.w = dot(pend_s3_glstate.pend_matrix.pend_mvp[3], pend_s4_IN.pend_endpos);
    dash1_pend_s3_v_0005 = (dash1_pend_s3_r_0001.xyz + dash1_pend_s3_r_0003.xyz)/2.0;
    dash1_pend_s3_x_0033 = dot(dash1_pend_s3_v_0005, dash1_pend_s3_v_0005);
    cash0_pend_s3__temp0004 = inversesqrt(dash1_pend_s3_x_0033)*dash1_pend_s3_v_0005;
    pend_s4_lineoffset = dash1_pend_s3_r_0003.xyz - dash1_pend_s3_r_0001.xyz;
    dash1_pend_s3_x_0037 = dot(pend_s4_lineoffset, pend_s4_lineoffset);
    cash0_pend_s3__temp0006 = inversesqrt(dash1_pend_s3_x_0037)*pend_s4_lineoffset;
    dash1_pend_s3_a_0011 = dot(cash0_pend_s3__temp0006, cash0_pend_s3__temp0004);
    pend_s4_texcoef = abs(dash1_pend_s3_a_0011);
    pend_s4_startpos2d = dash1_pend_s3_r_0001.xy/dash1_pend_s3_r_0001.w;
    pend_s4_endpos2d = dash1_pend_s3_r_0003.xy/dash1_pend_s3_r_0003.w;
    dash1_pend_s3_v_0013 = pend_s4_startpos2d - pend_s4_endpos2d;
    dash1_pend_s3_x_0041 = dot(dash1_pend_s3_v_0013, dash1_pend_s3_v_0013);
    cash0_pend_s3__temp0012 = inversesqrt(dash1_pend_s3_x_0041)*dash1_pend_s3_v_0013;
    pend_s4_posstart.xy = pend_s4_texcoef*gl_MultiTexCoord0.x*cash0_pend_s3__temp0012.xy + dash1_pend_s3_r_0001.xy;
    pend_s4_linedir2d = gl_MultiTexCoord1.x*cash0_pend_s3__temp0012;
    pend_s4_posstart.x = pend_s4_posstart.x + pend_s4_linedir2d.y;
    pend_s4_posstart.y = pend_s4_posstart.y - pend_s4_linedir2d.x;
    gl_Position = pend_s4_posstart;
    gl_PointSize = pend_s4_OUT.pend_endpos.x;
    gl_TexCoord[1].xyz = pend_s4_OUT.pend_param9;
    gl_TexCoord[0] = pend_s4_OUT.pend_param8;
    return;
} // main end
