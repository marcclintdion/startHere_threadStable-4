    if(copperEntrance_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &copperEntrance_COLORMAP); 
        copperEntrance_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(copperEntrance_VBO  != 0) 
    { 
        glDeleteBuffers(1, &copperEntrance_VBO); 
        copperEntrance_VBO  = 0; 
    } 
    if(copperEntrance_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &copperEntrance_INDICES_VBO); 
        copperEntrance_INDICES_VBO  = 0; 
    } 
