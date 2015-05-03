setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o10_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o10_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o10_POSITION[0] + moveSet[0],
                                o10_POSITION[1] + moveSet[1], 
                                o10_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o10_ROTATION[0],
                                o10_ROTATION[1], 
                                o10_ROTATION[2], 
                                o10_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 35970, GL_UNSIGNED_INT, 0); 
