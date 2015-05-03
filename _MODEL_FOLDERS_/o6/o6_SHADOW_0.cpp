setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o6_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o6_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o6_POSITION[0] + moveSet[0],
                                o6_POSITION[1] + moveSet[1], 
                                o6_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o6_ROTATION[0],
                                o6_ROTATION[1], 
                                o6_ROTATION[2], 
                                o6_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 36999, GL_UNSIGNED_INT, 0); 
