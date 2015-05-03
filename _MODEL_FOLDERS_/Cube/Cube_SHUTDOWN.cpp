    if(Cube_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &Cube_COLORMAP); 
        Cube_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(Cube_VBO  != 0) 
    { 
        glDeleteBuffers(1, &Cube_VBO); 
        Cube_VBO  = 0; 
    } 
    if(Cube_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &Cube_INDICES_VBO); 
        Cube_INDICES_VBO  = 0; 
    } 
