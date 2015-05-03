setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o1_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o1_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o1_POSITION[0] + moveSet[0],
                                o1_POSITION[1] + moveSet[1], 
                                o1_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o1_ROTATION[0],
                                o1_ROTATION[1], 
                                o1_ROTATION[2], 
                                o1_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 35271, GL_UNSIGNED_INT, 0); 
