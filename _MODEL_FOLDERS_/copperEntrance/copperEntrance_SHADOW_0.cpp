setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, copperEntrance_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, copperEntrance_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, copperEntrance_POSITION[0] + moveSet[0],
                                copperEntrance_POSITION[1] + moveSet[1], 
                                copperEntrance_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    copperEntrance_ROTATION[0],
                                copperEntrance_ROTATION[1], 
                                copperEntrance_ROTATION[2], 
                                copperEntrance_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 10395, GL_UNSIGNED_INT, 0); 
