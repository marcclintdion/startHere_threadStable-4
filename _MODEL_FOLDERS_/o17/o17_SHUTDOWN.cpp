    if(o17_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o17_COLORMAP); 
        o17_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o17_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o17_VBO); 
        o17_VBO  = 0; 
    } 
    if(o17_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o17_INDICES_VBO); 
        o17_INDICES_VBO  = 0; 
    } 
