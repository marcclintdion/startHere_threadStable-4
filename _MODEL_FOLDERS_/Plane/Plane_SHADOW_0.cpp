setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, Plane_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Plane_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, Plane_POSITION[0] + moveSet[0],
                                Plane_POSITION[1] + moveSet[1], 
                                Plane_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    Plane_ROTATION[0],
                                Plane_ROTATION[1], 
                                Plane_ROTATION[2], 
                                Plane_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
