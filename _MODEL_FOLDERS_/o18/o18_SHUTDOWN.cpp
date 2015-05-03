    if(o18_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o18_COLORMAP); 
        o18_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o18_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o18_VBO); 
        o18_VBO  = 0; 
    } 
    if(o18_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o18_INDICES_VBO); 
        o18_INDICES_VBO  = 0; 
    } 
