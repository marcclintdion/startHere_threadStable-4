    if(domeTree_x4_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &domeTree_x4_COLORMAP); 
        domeTree_x4_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(domeTree_x4_VBO  != 0) 
    { 
        glDeleteBuffers(1, &domeTree_x4_VBO); 
        domeTree_x4_VBO  = 0; 
    } 
    if(domeTree_x4_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &domeTree_x4_INDICES_VBO); 
        domeTree_x4_INDICES_VBO  = 0; 
    } 
