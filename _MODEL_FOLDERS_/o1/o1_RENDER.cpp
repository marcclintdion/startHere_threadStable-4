    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o1_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o1_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o1_FilePath = "_MODEL_FOLDERS_/o1/o1.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o1_FromHDtoSystemRAM, 0, NULL);                               
            o1_isLoaded = true;                                                             
        }                                                                                   
        if(o1_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o1, o1_COLORMAP, FreeImage_GetWidth(dib_o1),  FreeImage_GetHeight(dib_o1) );     
            delete_o1_FromSystemRAM();                                                      
            o1_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o1_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o1_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o1_POSITION[0] + moveSet[0], 
                                                o1_POSITION[1] + moveSet[1], 
                                                o1_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o1_ROTATION[0], 
                                                o1_ROTATION[1], 
                                                o1_ROTATION[2],  
                                                o1_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o1_ROTATION[0], 
                                                o1_ROTATION[1], 
                                                o1_ROTATION[2], 
                                                o1_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o1_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 35271, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o1_isActive == false && o1_isLoaded == true)                                         
    {                                                                                       
        if(o1_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o1_COLORMAP);                                              
            o1_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o1_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
