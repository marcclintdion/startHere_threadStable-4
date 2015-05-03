    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(domeTree_x4_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(domeTree_x4_isLoaded == false)                                                            
        {                                                                                   
            domeTree_x4_FilePath = "_MODEL_FOLDERS_/domeTree_x4/domeTree_x4.png";                                     
            _beginthread(load_domeTree_x4_FromHDtoSystemRAM, 0, NULL);                               
            domeTree_x4_isLoaded = true;                                                             
        }                                                                                   
        if(domeTree_x4_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_domeTree_x4, domeTree_x4_COLORMAP, FreeImage_GetWidth(dib_domeTree_x4),  FreeImage_GetHeight(dib_domeTree_x4) );     
            delete_domeTree_x4_FromSystemRAM();                                                      
            domeTree_x4_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                              
        //==================================                                              
                setupTransforms_MainColor();                                              
                    //--------------------------                                          
                    glBindBuffer(GL_ARRAY_BUFFER, domeTree_x4_VBO);                                
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, domeTree_x4_INDICES_VBO);                
                    //--------------------------------                                    
                    LoadIdentity(modelWorldMatrix);                                       
                    //--------------------------------------------------------            
                    Translate(modelWorldMatrix, domeTree_x4_POSITION[0] + moveSet[0], 
                                                domeTree_x4_POSITION[1] + moveSet[1], 
                                                domeTree_x4_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------            
                    Rotate(modelWorldMatrix,    domeTree_x4_ROTATION[0], 
                                                domeTree_x4_ROTATION[1], 
                                                domeTree_x4_ROTATION[2],  
                                                domeTree_x4_ROTATION[3]); 
                    //--------------------------------------------------------            
                    Scale(modelWorldMatrix,     domeTree_x4_SCALE[0], domeTree_x4_SCALE[1], domeTree_x4_SCALE[2]*1.0);
                    //--------------------------------------------------------            
                    LoadIdentity(modelRotationMatrix);                                    
                    //--------------------------------------------------------            
                    Rotate(modelRotationMatrix, domeTree_x4_ROTATION[0], 
                                                domeTree_x4_ROTATION[1], 
                                                domeTree_x4_ROTATION[2], 
                                                domeTree_x4_ROTATION[3]); 
                //===================================================                     
                SelectShader(shaderNumber);                                               
                //===================================================                     
                    glActiveTexture (GL_TEXTURE0);                                        
                    glBindTexture(GL_TEXTURE_2D, domeTree_x4_COLORMAP);                            
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 7485, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(domeTree_x4_isActive == false && domeTree_x4_isLoaded == true)                                         
    {                                                                                       
        if(domeTree_x4_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &domeTree_x4_COLORMAP);                                              
            domeTree_x4_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        domeTree_x4_isLoaded = false;                                                                
    }                                                                                       
