setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o5_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o5_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o5_POSITION[0] + moveSet[0],
                                o5_POSITION[1] + moveSet[1], 
                                o5_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o5_ROTATION[0],
                                o5_ROTATION[1], 
                                o5_ROTATION[2], 
                                o5_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 35661, GL_UNSIGNED_INT, 0); 
