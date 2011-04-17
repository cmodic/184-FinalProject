This is the framework for CS184 assignments.
See http://inst.eecs.berkeley.edu/~cs184/sp09/framework/

Author: Omer Sagy, Kevin Morgan
Login: cs184-ce, cs184-ca
SID: 21315388, 21051078

Description:
  4 images: picGOURAUD.png, picPHONG.png, picTEXTURE.png, picBUMP.png
  1 gif: rotate.gif
  sweep file: sweep.trk
  texture file: greenSpotTexture.png
  bump map file: spotBumpMap.png
  compiles with visual studio 2010

  NOTE: we purposely changed the color of the sweep from white to red so that the difference
  between gouraud and phong shading would be easier to discern. If you would like to reverse
  this, please change this line in the fragment shader: texcolor = vec4(1,0,0,0); to set the sweep
  color to whatever you want. 
  
