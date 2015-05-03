setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, rocks_o20_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o20_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, rocks_o20_POSITION[0] + moveSet[0],
                                rocks_o20_POSITION[1] + moveSet[1], 
                                rocks_o20_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    rocks_o20_ROTATION[0],
                                rocks_o20_ROTATION[1], 
                                rocks_o20_ROTATION[2], 
                                rocks_o20_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 4155, GL_UNSIGNED_INT, 0); 
