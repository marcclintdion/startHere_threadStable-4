setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o19_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o19_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o19_POSITION[0] + moveSet[0],
                                o19_POSITION[1] + moveSet[1], 
                                o19_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o19_ROTATION[0],
                                o19_ROTATION[1], 
                                o19_ROTATION[2], 
                                o19_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 35196, GL_UNSIGNED_INT, 0); 
