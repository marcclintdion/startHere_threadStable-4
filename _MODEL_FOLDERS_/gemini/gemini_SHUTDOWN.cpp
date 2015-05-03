    if(gemini_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &gemini_COLORMAP); 
        gemini_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(gemini_VBO  != 0) 
    { 
        glDeleteBuffers(1, &gemini_VBO); 
        gemini_VBO  = 0; 
    } 
    if(gemini_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &gemini_INDICES_VBO); 
        gemini_INDICES_VBO  = 0; 
    } 
