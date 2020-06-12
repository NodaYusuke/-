xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 79;
 0.00000;5.49300;0.00000;,
 0.00000;5.07487;-2.10208;,
 1.48640;5.07487;-1.48640;,
 0.00000;5.49300;0.00000;,
 2.10208;5.07487;0.00000;,
 0.00000;5.49300;0.00000;,
 1.48640;5.07487;1.48640;,
 0.00000;5.49300;0.00000;,
 -0.00000;5.07487;2.10208;,
 0.00000;5.49300;0.00000;,
 -1.48640;5.07487;1.48639;,
 0.00000;5.49300;0.00000;,
 -2.10208;5.07487;-0.00000;,
 0.00000;5.49300;0.00000;,
 -1.48640;5.07487;-1.48639;,
 0.00000;5.49300;0.00000;,
 0.00000;5.07487;-2.10208;,
 0.00000;3.88414;-3.88414;,
 2.74650;3.88414;-2.74650;,
 3.88414;3.88414;0.00000;,
 2.74650;3.88414;2.74650;,
 -0.00000;3.88414;3.88414;,
 -2.74650;3.88414;2.74650;,
 -3.88414;3.88414;-0.00000;,
 -2.74650;3.88414;-2.74650;,
 0.00000;3.88414;-3.88414;,
 0.00000;2.10208;-5.07487;,
 3.58847;2.10208;-3.58847;,
 5.07487;2.10208;0.00000;,
 3.58847;2.10208;3.58847;,
 -0.00000;2.10208;5.07487;,
 -3.58848;2.10208;3.58847;,
 -5.07487;2.10208;-0.00000;,
 -3.58848;2.10208;-3.58847;,
 0.00000;2.10208;-5.07487;,
 0.00000;-0.00000;-5.49300;,
 3.88414;-0.00000;-3.88414;,
 5.49300;-0.00000;0.00000;,
 3.88414;-0.00000;3.88414;,
 -0.00000;-0.00000;5.49300;,
 -3.88414;-0.00000;3.88414;,
 -5.49300;-0.00000;-0.00000;,
 -3.88414;-0.00000;-3.88414;,
 0.00000;-0.00000;-5.49300;,
 0.00000;-2.10208;-5.07487;,
 3.58847;-2.10208;-3.58847;,
 5.07487;-2.10208;0.00000;,
 3.58847;-2.10208;3.58847;,
 -0.00000;-2.10208;5.07487;,
 -3.58848;-2.10208;3.58847;,
 -5.07487;-2.10208;-0.00000;,
 -3.58848;-2.10208;-3.58847;,
 0.00000;-2.10208;-5.07487;,
 0.00000;-3.88414;-3.88414;,
 2.74650;-3.88414;-2.74650;,
 3.88414;-3.88414;0.00000;,
 2.74650;-3.88414;2.74650;,
 -0.00000;-3.88414;3.88414;,
 -2.74650;-3.88414;2.74650;,
 -3.88414;-3.88414;-0.00000;,
 -2.74650;-3.88414;-2.74650;,
 0.00000;-3.88414;-3.88414;,
 0.00000;-5.07487;-2.10208;,
 1.48640;-5.07487;-1.48640;,
 2.10208;-5.07487;0.00000;,
 1.48640;-5.07487;1.48640;,
 -0.00000;-5.07487;2.10208;,
 -1.48640;-5.07487;1.48640;,
 -2.10208;-5.07487;-0.00000;,
 -1.48640;-5.07487;-1.48640;,
 0.00000;-5.07487;-2.10208;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;,
 0.00000;-5.49300;-0.00000;;
 
 64;
 3;2,1,0;,
 3;4,2,3;,
 3;6,4,5;,
 3;8,6,7;,
 3;10,8,9;,
 3;12,10,11;,
 3;14,12,13;,
 3;16,14,15;,
 4;2,18,17,1;,
 4;4,19,18,2;,
 4;6,20,19,4;,
 4;8,21,20,6;,
 4;10,22,21,8;,
 4;12,23,22,10;,
 4;14,24,23,12;,
 4;16,25,24,14;,
 4;18,27,26,17;,
 4;19,28,27,18;,
 4;20,29,28,19;,
 4;21,30,29,20;,
 4;22,31,30,21;,
 4;23,32,31,22;,
 4;24,33,32,23;,
 4;25,34,33,24;,
 4;27,36,35,26;,
 4;28,37,36,27;,
 4;29,38,37,28;,
 4;30,39,38,29;,
 4;31,40,39,30;,
 4;32,41,40,31;,
 4;33,42,41,32;,
 4;34,43,42,33;,
 4;36,45,44,35;,
 4;37,46,45,36;,
 4;38,47,46,37;,
 4;39,48,47,38;,
 4;40,49,48,39;,
 4;41,50,49,40;,
 4;42,51,50,41;,
 4;43,52,51,42;,
 4;45,54,53,44;,
 4;46,55,54,45;,
 4;47,56,55,46;,
 4;48,57,56,47;,
 4;49,58,57,48;,
 4;50,59,58,49;,
 4;51,60,59,50;,
 4;52,61,60,51;,
 4;54,63,62,53;,
 4;55,64,63,54;,
 4;56,65,64,55;,
 4;57,66,65,56;,
 4;58,67,66,57;,
 4;59,68,67,58;,
 4;60,69,68,59;,
 4;61,70,69,60;,
 3;63,71,62;,
 3;64,72,63;,
 3;65,73,64;,
 3;66,74,65;,
 3;67,75,66;,
 3;68,76,67;,
 3;69,77,68;,
 3;70,78,69;;
 
 MeshMaterialList {
  1;
  64;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  58;
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.924735;0.380611;,
  -0.269133;-0.924735;0.269133;,
  -0.380611;-0.924735;-0.000000;,
  -0.269132;-0.924735;-0.269133;,
  0.000000;-0.924735;-0.380611;,
  0.269133;-0.924735;-0.269132;,
  0.380611;-0.924735;-0.000000;,
  0.269133;-0.924735;0.269132;,
  0.000000;-0.709230;0.704977;,
  -0.498494;-0.709230;0.498494;,
  -0.704977;-0.709230;-0.000000;,
  -0.498494;-0.709230;-0.498494;,
  0.000000;-0.709230;-0.704977;,
  0.498494;-0.709230;-0.498494;,
  0.704977;-0.709230;-0.000000;,
  0.498494;-0.709230;0.498494;,
  0.000000;-0.384551;0.923104;,
  -0.652733;-0.384551;0.652733;,
  -0.923104;-0.384551;-0.000000;,
  -0.652733;-0.384551;-0.652733;,
  0.000000;-0.384551;-0.923104;,
  0.652733;-0.384551;-0.652733;,
  0.923104;-0.384551;-0.000000;,
  0.652733;-0.384551;0.652733;,
  0.000000;0.000000;1.000000;,
  -0.707107;-0.000000;0.707107;,
  -1.000000;0.000000;-0.000000;,
  -0.707107;-0.000000;-0.707107;,
  0.000000;-0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;-0.000000;,
  0.707107;-0.000000;0.707107;,
  0.000000;0.384551;0.923104;,
  -0.652733;0.384551;0.652733;,
  -0.923104;0.384551;0.000000;,
  -0.652733;0.384551;-0.652733;,
  0.000000;0.384551;-0.923104;,
  0.652733;0.384551;-0.652733;,
  0.923104;0.384551;-0.000000;,
  0.652733;0.384551;0.652733;,
  0.000000;0.709230;0.704977;,
  -0.498494;0.709230;0.498494;,
  -0.704977;0.709230;0.000000;,
  -0.498494;0.709230;-0.498494;,
  0.000000;0.709230;-0.704977;,
  0.498494;0.709230;-0.498494;,
  0.704977;0.709230;0.000000;,
  0.498494;0.709230;0.498494;,
  0.000000;0.924735;0.380611;,
  -0.269133;0.924735;0.269133;,
  -0.380611;0.924735;-0.000000;,
  -0.269133;0.924735;-0.269133;,
  0.000000;0.924735;-0.380611;,
  0.269133;0.924735;-0.269132;,
  0.380611;0.924735;0.000000;,
  0.269133;0.924735;0.269132;,
  0.000000;1.000000;0.000000;;
  64;
  3;2,1,0;,
  3;3,2,0;,
  3;4,3,0;,
  3;5,4,0;,
  3;6,5,0;,
  3;7,6,0;,
  3;8,7,0;,
  3;1,8,0;,
  4;2,10,9,1;,
  4;3,11,10,2;,
  4;4,12,11,3;,
  4;5,13,12,4;,
  4;6,14,13,5;,
  4;7,15,14,6;,
  4;8,16,15,7;,
  4;1,9,16,8;,
  4;10,18,17,9;,
  4;11,19,18,10;,
  4;12,20,19,11;,
  4;13,21,20,12;,
  4;14,22,21,13;,
  4;15,23,22,14;,
  4;16,24,23,15;,
  4;9,17,24,16;,
  4;18,26,25,17;,
  4;19,27,26,18;,
  4;20,28,27,19;,
  4;21,29,28,20;,
  4;22,30,29,21;,
  4;23,31,30,22;,
  4;24,32,31,23;,
  4;17,25,32,24;,
  4;26,34,33,25;,
  4;27,35,34,26;,
  4;28,36,35,27;,
  4;29,37,36,28;,
  4;30,38,37,29;,
  4;31,39,38,30;,
  4;32,40,39,31;,
  4;25,33,40,32;,
  4;34,42,41,33;,
  4;35,43,42,34;,
  4;36,44,43,35;,
  4;37,45,44,36;,
  4;38,46,45,37;,
  4;39,47,46,38;,
  4;40,48,47,39;,
  4;33,41,48,40;,
  4;42,50,49,41;,
  4;43,51,50,42;,
  4;44,52,51,43;,
  4;45,53,52,44;,
  4;46,54,53,45;,
  4;47,55,54,46;,
  4;48,56,55,47;,
  4;41,49,56,48;,
  3;50,57,49;,
  3;51,57,50;,
  3;52,57,51;,
  3;53,57,52;,
  3;54,57,53;,
  3;55,57,54;,
  3;56,57,55;,
  3;49,57,56;;
 }
 MeshTextureCoords {
  79;
  0.062500;0.000000;
  0.000000;0.125000;
  0.125000;0.125000;
  0.187500;0.000000;
  0.250000;0.125000;
  0.312500;0.000000;
  0.375000;0.125000;
  0.437500;0.000000;
  0.500000;0.125000;
  0.562500;0.000000;
  0.625000;0.125000;
  0.687500;0.000000;
  0.750000;0.125000;
  0.812500;0.000000;
  0.875000;0.125000;
  0.937500;0.000000;
  1.000000;0.125000;
  0.000000;0.250000;
  0.125000;0.250000;
  0.250000;0.250000;
  0.375000;0.250000;
  0.500000;0.250000;
  0.625000;0.250000;
  0.750000;0.250000;
  0.875000;0.250000;
  1.000000;0.250000;
  0.000000;0.375000;
  0.125000;0.375000;
  0.250000;0.375000;
  0.375000;0.375000;
  0.500000;0.375000;
  0.625000;0.375000;
  0.750000;0.375000;
  0.875000;0.375000;
  1.000000;0.375000;
  0.000000;0.500000;
  0.125000;0.500000;
  0.250000;0.500000;
  0.375000;0.500000;
  0.500000;0.500000;
  0.625000;0.500000;
  0.750000;0.500000;
  0.875000;0.500000;
  1.000000;0.500000;
  0.000000;0.625000;
  0.125000;0.625000;
  0.250000;0.625000;
  0.375000;0.625000;
  0.500000;0.625000;
  0.625000;0.625000;
  0.750000;0.625000;
  0.875000;0.625000;
  1.000000;0.625000;
  0.000000;0.750000;
  0.125000;0.750000;
  0.250000;0.750000;
  0.375000;0.750000;
  0.500000;0.750000;
  0.625000;0.750000;
  0.750000;0.750000;
  0.875000;0.750000;
  1.000000;0.750000;
  0.000000;0.875000;
  0.125000;0.875000;
  0.250000;0.875000;
  0.375000;0.875000;
  0.500000;0.875000;
  0.625000;0.875000;
  0.750000;0.875000;
  0.875000;0.875000;
  1.000000;0.875000;
  0.062500;1.000000;
  0.187500;1.000000;
  0.312500;1.000000;
  0.437500;1.000000;
  0.562500;1.000000;
  0.687500;1.000000;
  0.812500;1.000000;
  0.937500;1.000000;;
 }
}
