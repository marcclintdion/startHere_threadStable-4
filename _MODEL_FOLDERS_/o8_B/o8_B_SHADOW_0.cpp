setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o8_B_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o8_B_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o8_B_POSITION[0] + moveSet[0],
                                o8_B_POSITION[1] + moveSet[1], 
                                o8_B_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o8_B_ROTATION[0],
                                o8_B_ROTATION[1], 
                                o8_B_ROTATION[2], 
                                o8_B_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 33690, GL_UNSIGNED_INT, 0); 
