setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o16_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o16_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o16_POSITION[0] + moveSet[0],
                                o16_POSITION[1] + moveSet[1], 
                                o16_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o16_ROTATION[0],
                                o16_ROTATION[1], 
                                o16_ROTATION[2], 
                                o16_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 33972, GL_UNSIGNED_INT, 0); 
