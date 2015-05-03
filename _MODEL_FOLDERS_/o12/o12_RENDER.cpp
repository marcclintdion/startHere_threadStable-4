    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o12_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o12_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o12_FilePath = "_MODEL_FOLDERS_/o12/o12.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o12_FromHDtoSystemRAM, 0, NULL);                               
            o12_isLoaded = true;                                                             
        }                                                                                   
        if(o12_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o12, o12_COLORMAP, FreeImage_GetWidth(dib_o12),  FreeImage_GetHeight(dib_o12) );     
            delete_o12_FromSystemRAM();                                                      
            o12_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
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
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o12_ROTATION[0], 
                                                o12_ROTATION[1], 
                                                o12_ROTATION[2], 
                                                o12_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o12_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 28962, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o12_isActive == false && o12_isLoaded == true)                                         
    {                                                                                       
        if(o12_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o12_COLORMAP);                                              
            o12_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o12_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
