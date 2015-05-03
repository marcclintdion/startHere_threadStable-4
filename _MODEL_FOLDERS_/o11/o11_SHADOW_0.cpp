setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o11_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o11_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o11_POSITION[0] + moveSet[0],
                                o11_POSITION[1] + moveSet[1], 
                                o11_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o11_ROTATION[0],
                                o11_ROTATION[1], 
                                o11_ROTATION[2], 
                                o11_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 34866, GL_UNSIGNED_INT, 0); 
