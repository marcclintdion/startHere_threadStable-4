setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o9_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o9_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o9_POSITION[0] + moveSet[0],
                                o9_POSITION[1] + moveSet[1], 
                                o9_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o9_ROTATION[0],
                                o9_ROTATION[1], 
                                o9_ROTATION[2], 
                                o9_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 37329, GL_UNSIGNED_INT, 0); 
