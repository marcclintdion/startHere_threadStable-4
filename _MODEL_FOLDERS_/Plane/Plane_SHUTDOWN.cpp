    if(Plane_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &Plane_COLORMAP); 
        Plane_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(Plane_VBO  != 0) 
    { 
        glDeleteBuffers(1, &Plane_VBO); 
        Plane_VBO  = 0; 
    } 
    if(Plane_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &Plane_INDICES_VBO); 
        Plane_INDICES_VBO  = 0; 
    } 
