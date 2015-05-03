setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, rocks_o18_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o18_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, rocks_o18_POSITION[0] + moveSet[0],
                                rocks_o18_POSITION[1] + moveSet[1], 
                                rocks_o18_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    rocks_o18_ROTATION[0],
                                rocks_o18_ROTATION[1], 
                                rocks_o18_ROTATION[2], 
                                rocks_o18_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 8181, GL_UNSIGNED_INT, 0); 
