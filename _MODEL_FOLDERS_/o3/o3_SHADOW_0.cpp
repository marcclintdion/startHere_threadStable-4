setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o3_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o3_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o3_POSITION[0] + moveSet[0],
                                o3_POSITION[1] + moveSet[1], 
                                o3_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o3_ROTATION[0],
                                o3_ROTATION[1], 
                                o3_ROTATION[2], 
                                o3_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 37767, GL_UNSIGNED_INT, 0); 
