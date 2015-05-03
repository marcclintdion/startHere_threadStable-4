    if(o3_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o3_COLORMAP); 
        o3_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o3_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o3_VBO); 
        o3_VBO  = 0; 
    } 
    if(o3_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o3_INDICES_VBO); 
        o3_INDICES_VBO  = 0; 
    } 
