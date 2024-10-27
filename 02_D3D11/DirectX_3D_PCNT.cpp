// DirectX values for position, color, texcoords, normal for pyradmid and cube

// PYRAMID

// position
const float pyramidPosition[] = 
{
	 // front
	+0.0f, +1.0f, +0.0f, // front-top
	+1.0f, -1.0f, -1.0f, // front-right
	-1.0f, -1.0f, -1.0f, // front-left
	
	// right
    +0.0f, +1.0f, +0.0f, // right-top
	+1.0f, -1.0f, +1.0f, // right-right
	+1.0f, -1.0f, -1.0f, // right-left

	// back
	+0.0f, +1.0f, +0.0f, // back-top
	-1.0f, -1.0f, +1.0f, // back-right
	+1.0f, -1.0f, +1.0f, // back-left

	// left
	+0.0f, +1.0f, +0.0f, // left-top
	-1.0f, -1.0f, -1.0f, // left-right
	-1.0f, -1.0f, +1.0f, // left-left
};

// color
const float pyramidColors[] =
{
	// front
	1.0f, 0.0f, 0.0f, // front-top
	0.0f, 0.0f, 1.0f, // front-left
	0.0f, 1.0f, 0.0f, // front-right
	
	// right
	1.0f, 0.0f, 0.0f, // right-top
	0.0f, 1.0f, 0.0f, // right-right
	0.0f, 0.0f, 1.0f, // right-left
	
	// back
	1.0f, 0.0f, 0.0f, // back-top
	0.0f, 0.0f, 1.0f, // back-right
	0.0f, 1.0f, 0.0f, // back-left
	
	// left
	1.0f, 0.0f, 0.0f, // left-top
	0.0f, 1.0f, 0.0f, // left-right
	0.0f, 0.0f, 1.0f, // left-left
};

// normals
const float pyramidNormals[] =
{
	// front
	+0.0f, +0.447214f, -0.894427f, // front-top
	+0.0f, +0.447214f, -0.894427f, // front-right
	+0.0f, +0.447214f, -0.894427f, // front-left
						    
	// right			    
	+0.894427f, +0.447214f, +0.0f, // right-top
	+0.894427f, +0.447214f, +0.0f, // right-right
	+0.894427f, +0.447214f, +0.0f, // right-left

	// back
	+0.0f, +0.447214f, +0.894427f, // back-top
	+0.0f, +0.447214f, +0.894427f, // back-right
	+0.0f, +0.447214f, +0.894427f, // back-left

	// left
	-0.894427f, +0.447214f, +0.0f, // left-top
	-0.894427f, +0.447214f, +0.0f, // left-right
	-0.894427f, +0.447214f, +0.0f, // left-left
};

// texcoords
const float pyramidTexcoords[] =
{
	// front
	0.5, 1.0, // front-top
	1.0, 0.0, // front-right
	0.0, 0.0, // front-left

	// right
	0.5, 1.0, // right-top
	0.0, 0.0, // right-right
	1.0, 0.0, // right-left

	// back
	0.5, 1.0, // back-top
	1.0, 0.0, // back-right
	0.0, 0.0, // back-left

	// left
	0.5, 1.0, // left-top
	0.0, 0.0, // left-right
	1.0, 0.0, // left-left
};

const float pyramid_PCNT[] =
{
	// position : x,y,z    color : r,g,b          normal : x,y,z                   Tex : u,v
	// front
	+0.0f, +1.0f, +0.0f,   +1.0f, +0.0f, +0.0f,   +0.0f, +0.447214f, -0.894427f,   +0.5, +1.0, // front-top
	+1.0f, -1.0f, -1.0f,   +0.0f, +0.0f, +1.0f,   +0.0f, +0.447214f, -0.894427f,   +1.0, +0.0, // front-right
	-1.0f, -1.0f, -1.0f,   +0.0f, +1.0f, +0.0f,   +0.0f, +0.447214f, -0.894427f,   +0.0, +0.0, // front-left

	// right
	+0.0f, +1.0f, +0.0f,   +1.0f, +0.0f, +0.0f,   +0.894427f, +0.447214f, +0.0f,   +0.5, +1.0, // right-top
	+1.0f, -1.0f, +1.0f,   +0.0f, +1.0f, +0.0f,   +0.894427f, +0.447214f, +0.0f,   +0.0, +0.0, // right-right
	+1.0f, -1.0f, -1.0f,   +0.0f, +0.0f, +1.0f,   +0.894427f, +0.447214f, +0.0f,   +1.0, +0.0, // right-left

	// back
	+0.0f, +1.0f, +0.0f,   +1.0f, +0.0f, +0.0f,   +0.0f, +0.447214f, +0.894427f,   +0.5, +1.0, // back-top
	-1.0f, -1.0f, +1.0f,   +0.0f, +0.0f, +1.0f,   +0.0f, +0.447214f, +0.894427f,   +1.0, +0.0, // back-right
	+1.0f, -1.0f, +1.0f,   +0.0f, +1.0f, +0.0f,   +0.0f, +0.447214f, +0.894427f,   +0.0, +0.0, // back-left

	// left
	+0.0f, +1.0f, +0.0f,   +1.0f, +0.0f, +0.0f,   -0.894427f, +0.447214f, +0.0f,   +0.5, +1.0, // left-top
	-1.0f, -1.0f, -1.0f,   +0.0f, +1.0f, +0.0f,   -0.894427f, +0.447214f, +0.0f,   +0.0, +0.0, // left-right
	-1.0f, -1.0f, +1.0f,   +0.0f, +0.0f, +1.0f,   -0.894427f, +0.447214f, +0.0f,   +1.0, +0.0, // left-left
};

// =======================================================================================================================================================

// CUBE :

// position
const float cubePositions[] =
{
	// front
	-1.0f, +1.0f, -1.0f, // top-left of front
	+1.0f, +1.0f, -1.0f, // top-right of front
	-1.0f, -1.0f, -1.0f, // bottom-left of front

	-1.0f, -1.0f, -1.0f, // bottom-left of front
	+1.0f, +1.0f, -1.0f, // top-right of front
	+1.0f, -1.0f, -1.0f, // bottom-right of front
	
	// right
	+1.0f, +1.0f, -1.0f, // top-left of right
	+1.0f, +1.0f, +1.0f, // top-right of right
	+1.0f, -1.0f, -1.0f, // bottom-left of right

	+1.0f, -1.0f, -1.0f, // bottom-left of right
	+1.0f, +1.0f, +1.0f, // top-right of right
	+1.0f, -1.0f, +1.0f, // bottom-right of right

	// back
	+1.0f, +1.0f, +1.0f, // top-left of back
	-1.0f, +1.0f, +1.0f, // top-right of back
	+1.0f, -1.0f, +1.0f, // bottom-left of back

	+1.0f, -1.0f, +1.0f, // bottom-left of back
	-1.0f, +1.0f, +1.0f, // top-right of back
	-1.0f, -1.0f, +1.0f, // bottom-right of back

	// left
	-1.0f, +1.0f, +1.0f, // top-left of left
	-1.0f, +1.0f, -1.0f, // top-right of left
	-1.0f, -1.0f, +1.0f, // bottom-left of left

	-1.0f, -1.0f, +1.0f, // bottom-left of left
	-1.0f, +1.0f, -1.0f, // top-right of left
	-1.0f, -1.0f, -1.0f, // bottom-right of left

	// top
	-1.0f, +1.0f, +1.0f, // top-left of top
	+1.0f, +1.0f, +1.0f, // top-right of top
	-1.0f, +1.0f, -1.0f, // bottom-left of top

	-1.0f, +1.0f, -1.0f, // bottom-left of top
	+1.0f, +1.0f, +1.0f, // top-right of top
	+1.0f, +1.0f, -1.0f, // bottom-right of top

	// bottom
	-1.0f, -1.0f, -1.0f, // top-left of bottom
	+1.0f, -1.0f, -1.0f, // top-right of bottom
	-1.0f, -1.0f, +1.0f, // bottom-left of bottom

	-1.0f, -1.0f, +1.0f, // bottom-left of bottom
	+1.0f, -1.0f, -1.0f, // top-right of bottom
	+1.0f, -1.0f, +1.0f, // bottom-right of bottom
};

// color
const float cubeColors[] =
{
	// front
	1.0f, 0.0f, 0.0f, // top-left of front
	1.0f, 0.0f, 0.0f, // top-right of front
	1.0f, 0.0f, 0.0f, // bottom-left of front

	1.0f, 0.0f, 0.0f, // bottom-left of front
	1.0f, 0.0f, 0.0f, // top-right of front
	1.0f, 0.0f, 0.0f, // bottom-right of front
	
	// right
	0.0f, 0.0f, 1.0f, // top-left of right
	0.0f, 0.0f, 1.0f, // top-right of right
	0.0f, 0.0f, 1.0f, // bottom-left of right

	0.0f, 0.0f, 1.0f, // bottom-left of right
	0.0f, 0.0f, 1.0f, // top-right of right
	0.0f, 0.0f, 1.0f, // bottom-right of right

	// back
	1.0f, 1.0f, 0.0f, // top-left of back
	1.0f, 1.0f, 0.0f, // top-right of back
	1.0f, 1.0f, 0.0f, // bottom-left of back

	1.0f, 1.0f, 0.0f, // bottom-left of back
	1.0f, 1.0f, 0.0f, // top-right of back
	1.0f, 1.0f, 0.0f, // bottom-right of back

	// left
	1.0f, 0.0f, 1.0f, // top-left of left
	1.0f, 0.0f, 1.0f, // top-right of left
	1.0f, 0.0f, 1.0f, // bottom-left of left

	1.0f, 0.0f, 1.0f, // bottom-left of left
	1.0f, 0.0f, 1.0f, // top-right of left
	1.0f, 0.0f, 1.0f, // bottom-right of left

	// top
	0.0f, 1.0f, 0.0f, // top-left of top
	0.0f, 1.0f, 0.0f, // top-right of top
	0.0f, 1.0f, 0.0f, // bottom-left of top

	0.0f, 1.0f, 0.0f, // bottom-left of top
	0.0f, 1.0f, 0.0f, // top-right of top
	0.0f, 1.0f, 0.0f, // bottom-right of top

	// bottom
	1.0f, 0.5f, 0.0f, // top-left of bottom
	1.0f, 0.5f, 0.0f, // top-right of bottom
	1.0f, 0.5f, 0.0f, // bottom-left of bottom

	1.0f, 0.5f, 0.0f, // bottom-left of bottom
	1.0f, 0.5f, 0.0f, // top-right of bottom
	1.0f, 0.5f, 0.0f, // bottom-right of bottom
};

// normal
const float cubeNormals[] =
{
	// front
	+0.0f, +0.0f, -1.0f, // top-left of front
	+0.0f, +0.0f, -1.0f, // top-right of front
	+0.0f, +0.0f, -1.0f, // bottom-left of front

	+0.0f, +0.0f, -1.0f, // bottom-left of front
	+0.0f, +0.0f, -1.0f, // top-right of front
	+0.0f, +0.0f, -1.0f, // bottom-right of front
	
	// right
	+1.0f, +0.0f, +0.0f, // top-left of right
	+1.0f, +0.0f, +0.0f, // top-right of right
	+1.0f, +0.0f, +0.0f, // bottom-left of right

	+1.0f, +0.0f, +0.0f, // bottom-left of right
	+1.0f, +0.0f, +0.0f, // top-right of right
	+1.0f, +0.0f, +0.0f, // bottom-right of right

	// back
	+0.0f, +0.0f, +1.0f, // top-left of back
	+0.0f, +0.0f, +1.0f, // top-right of back
	+0.0f, +0.0f, +1.0f, // bottom-left of back

	+0.0f, +0.0f, +1.0f, // bottom-left of back
	+0.0f, +0.0f, +1.0f, // top-right of back
	+0.0f, +0.0f, +1.0f, // bottom-right of back

	// left
	-1.0f, +0.0f, +0.0f, // top-left of left
	-1.0f, +0.0f, +0.0f, // top-right of left
	-1.0f, +0.0f, +0.0f, // bottom-left of left

	-1.0f, +0.0f, +0.0f, // bottom-left of left
	-1.0f, +0.0f, +0.0f, // top-right of left
	-1.0f, +0.0f, +0.0f, // bottom-right of left

	// top
	+0.0f, +1.0f, +0.0f, // top-left of top
	+0.0f, +1.0f, +0.0f, // top-right of top
	+0.0f, +1.0f, +0.0f, // bottom-left of top

	+0.0f, +1.0f, +0.0f, // bottom-left of top
	+0.0f, +1.0f, +0.0f, // top-right of top
	+0.0f, +1.0f, +0.0f, // bottom-right of top

	// bottom
	+0.0f, -1.0f, +0.0f, // top-left of bottom
	+0.0f, -1.0f, +0.0f, // top-right of bottom
	+0.0f, -1.0f, +0.0f, // bottom-left of bottom

	+0.0f, -1.0f, +0.0f, // bottom-left of bottom
	+0.0f, -1.0f, +0.0f, // top-right of bottom
	+0.0f, -1.0f, +0.0f, // bottom-right of bottom
};

// texcoords
const float cubeTexCoords[] =
{
	// front
	0.0f, 1.0f, // top-left of front
	1.0f, 1.0f, // top-right of front
	0.0f, 0.0f, // bottom-left of front

	0.0f, 0.0f, // bottom-left of front
	1.0f, 1.0f, // top-right of front
	1.0f, 0.0f, // bottom-right of front
	
	// right
	0.0f, 1.0f, // top-left of right
	1.0f, 1.0f, // top-right of right
	0.0f, 0.0f, // bottom-left of right

	0.0f, 0.0f, // bottom-left of right
	1.0f, 1.0f, // top-right of right
	1.0f, 0.0f, // bottom-right of right

	// back
	0.0f, 1.0f, // top-left of back
	1.0f, 1.0f, // top-right of back
	0.0f, 0.0f, // bottom-left of back

	0.0f, 0.0f, // bottom-left of back
	1.0f, 1.0f, // top-right of back
	1.0f, 0.0f, // bottom-right of back

	// left
	0.0f, 1.0f, // top-left of left
	1.0f, 1.0f, // top-right of left
	0.0f, 0.0f, // bottom-left of left

	0.0f, 0.0f, // bottom-left of left
	1.0f, 1.0f, // top-right of left
	1.0f, 0.0f, // bottom-right of left

	// top
	0.0f, 1.0f, // top-left of top
	1.0f, 1.0f, // top-right of top
	0.0f, 0.0f, // bottom-left of top

	0.0f, 0.0f, // bottom-left of top
	1.0f, 1.0f, // top-right of top
	1.0f, 0.0f, // bottom-right of top

	// bottom
	0.0f, 1.0f, // top-left of bottom
	1.0f, 1.0f, // top-right of bottom
	0.0f, 0.0f, // bottom-left of bottom

	0.0f, 0.0f, // bottom-left of bottom
	1.0f, 1.0f, // top-right of bottom
	1.0f, 0.0f, // bottom-right of bottom
};

const float cube_PCNT[] =
{
	// position : x,y,z    color : r,g,b          normal : x,y,z         Tex : u,v
	// SIDE 1 ( FRONT )
	-1.0f, +1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   +0.0f, +0.0f, -1.0f,   0.0f, 1.0f, // top-left of front
	+1.0f, +1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   +0.0f, +0.0f, -1.0f,   1.0f, 1.0f, // top-right of front
	-1.0f, -1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   +0.0f, +0.0f, -1.0f,   0.0f, 0.0f, // bottom-left of front

	-1.0f, -1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   +0.0f, +0.0f, -1.0f,   0.0f, 0.0f, // bottom-left of front
	+1.0f, +1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   +0.0f, +0.0f, -1.0f,   1.0f, 1.0f, // top-right of front
	+1.0f, -1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   +0.0f, +0.0f, -1.0f,   1.0f, 0.0f, // bottom-right of front

	// SIDE 2 ( RIGHT )
	+1.0f, +1.0f, -1.0f,   0.0f, 0.0f, 1.0f,   +1.0f, +0.0f, +0.0f,   0.0f, 1.0f, // top-left of right
	+1.0f, +1.0f, +1.0f,   0.0f, 0.0f, 1.0f,   +1.0f, +0.0f, +0.0f,   1.0f, 1.0f, // top-right of right
	+1.0f, -1.0f, -1.0f,   0.0f, 0.0f, 1.0f,   +1.0f, +0.0f, +0.0f,   0.0f, 0.0f, // bottom-left of right

	+1.0f, -1.0f, -1.0f,   0.0f, 0.0f, 1.0f,   +1.0f, +0.0f, +0.0f,   0.0f, 0.0f, // bottom-left of right
	+1.0f, +1.0f, +1.0f,   0.0f, 0.0f, 1.0f,   +1.0f, +0.0f, +0.0f,   1.0f, 1.0f, // top-right of right
	+1.0f, -1.0f, +1.0f,   0.0f, 0.0f, 1.0f,   +1.0f, +0.0f, +0.0f,   1.0f, 0.0f, // bottom-right of right

	// SIDE 3 ( BACK )
	+1.0f, +1.0f, +1.0f,   1.0f, 1.0f, 0.0f,   +0.0f, +0.0f, +1.0f,   0.0f, 1.0f, // top-left of back
	-1.0f, +1.0f, +1.0f,   1.0f, 1.0f, 0.0f,   +0.0f, +0.0f, +1.0f,   1.0f, 1.0f, // top-right of back
	+1.0f, -1.0f, +1.0f,   1.0f, 1.0f, 0.0f,   +0.0f, +0.0f, +1.0f,   0.0f, 0.0f, // bottom-left of back

	+1.0f, -1.0f, +1.0f,   1.0f, 1.0f, 0.0f,   +0.0f, +0.0f, +1.0f,   0.0f, 0.0f, // bottom-left of back
	-1.0f, +1.0f, +1.0f,   1.0f, 1.0f, 0.0f,   +0.0f, +0.0f, +1.0f,   1.0f, 1.0f, // top-right of back
	-1.0f, -1.0f, +1.0f,   1.0f, 1.0f, 0.0f,   +0.0f, +0.0f, +1.0f,   1.0f, 0.0f, // bottom-right of back

	// SIDE 4 ( LEFT )
	-1.0f, +1.0f, +1.0f,   1.0f, 0.0f, 1.0f,   -1.0f, +0.0f, +0.0f,   0.0f, 1.0f, // top-left of left
	-1.0f, +1.0f, -1.0f,   1.0f, 0.0f, 1.0f,   -1.0f, +0.0f, +0.0f,   1.0f, 1.0f, // top-right of left
	-1.0f, -1.0f, +1.0f,   1.0f, 0.0f, 1.0f,   -1.0f, +0.0f, +0.0f,   0.0f, 0.0f, // bottom-left of left

	-1.0f, -1.0f, +1.0f,   1.0f, 0.0f, 1.0f,   -1.0f, +0.0f, +0.0f,   0.0f, 0.0f, // bottom-left of left
	-1.0f, +1.0f, -1.0f,   1.0f, 0.0f, 1.0f,   -1.0f, +0.0f, +0.0f,   1.0f, 1.0f, // top-right of left
	-1.0f, -1.0f, -1.0f,   1.0f, 0.0f, 1.0f,   -1.0f, +0.0f, +0.0f,   1.0f, 0.0f, // bottom-right of left

	// SIDE 5 ( TOP )
	-1.0f, +1.0f, +1.0f,   0.0f, 1.0f, 0.0f,   +0.0f, +1.0f, +0.0f,   0.0f, 1.0f, // top-left of top
	+1.0f, +1.0f, +1.0f,   0.0f, 1.0f, 0.0f,   +0.0f, +1.0f, +0.0f,   1.0f, 1.0f, // top-right of top
	-1.0f, +1.0f, -1.0f,   0.0f, 1.0f, 0.0f,   +0.0f, +1.0f, +0.0f,   0.0f, 0.0f, // bottom-left of top

	-1.0f, +1.0f, -1.0f,   0.0f, 1.0f, 0.0f,   +0.0f, +1.0f, +0.0f,   0.0f, 0.0f, // bottom-left of top
	+1.0f, +1.0f, +1.0f,   0.0f, 1.0f, 0.0f,   +0.0f, +1.0f, +0.0f,   1.0f, 1.0f, // top-right of top
	+1.0f, +1.0f, -1.0f,   0.0f, 1.0f, 0.0f,   +0.0f, +1.0f, +0.0f,   1.0f, 0.0f, // bottom-right of top

	// SIDE 6 ( BOTTOM )
	-1.0f, -1.0f, -1.0f,   1.0f, 0.5f, 0.0f,   +0.0f, -1.0f, +0.0f,   0.0f, 1.0f, // top-left of bottom
	+1.0f, -1.0f, -1.0f,   1.0f, 0.5f, 0.0f,   +0.0f, -1.0f, +0.0f,   1.0f, 1.0f, // top-right of bottom
	-1.0f, -1.0f, +1.0f,   1.0f, 0.5f, 0.0f,   +0.0f, -1.0f, +0.0f,   0.0f, 0.0f, // bottom-left of bottom

	-1.0f, -1.0f, +1.0f,   1.0f, 0.5f, 0.0f,   +0.0f, -1.0f, +0.0f,   0.0f, 0.0f, // bottom-left of bottom
	+1.0f, -1.0f, -1.0f,   1.0f, 0.5f, 0.0f,   +0.0f, -1.0f, +0.0f,   1.0f, 1.0f, // top-right of bottom
	+1.0f, -1.0f, +1.0f,   1.0f, 0.5f, 0.0f,   +0.0f, -1.0f, +0.0f,   1.0f, 0.0f, // bottom-right of bottom
};
