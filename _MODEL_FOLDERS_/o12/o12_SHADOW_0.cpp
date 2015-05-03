setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o12_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o12_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o12_POSITION[0] + moveSet[0],
                                o12_POSITION[1] + moveSet[1], 
                                o12_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o12_ROTATION[0],
                                o12_ROTATION[1], 
                                o12_ROTATION[2], 
                                o12_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 28962, GL_UNSIGNED_INT, 0); 
