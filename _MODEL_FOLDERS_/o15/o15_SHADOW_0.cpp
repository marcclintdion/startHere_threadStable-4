setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o15_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o15_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o15_POSITION[0] + moveSet[0],
                                o15_POSITION[1] + moveSet[1], 
                                o15_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o15_ROTATION[0],
                                o15_ROTATION[1], 
                                o15_ROTATION[2], 
                                o15_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 33873, GL_UNSIGNED_INT, 0); 
