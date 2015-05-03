    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(rocks_o20_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(rocks_o20_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            rocks_o20_FilePath = "_MODEL_FOLDERS_/rocks_o20/o20_rocks.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_rocks_o20_FromHDtoSystemRAM, 0, NULL);                               
            rocks_o20_isLoaded = true;                                                             
        }                                                                                   
        if(rocks_o20_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_rocks_o20, rocks_o20_COLORMAP, FreeImage_GetWidth(dib_rocks_o20),  FreeImage_GetHeight(dib_rocks_o20) );     
            delete_rocks_o20_FromSystemRAM();                                                      
            rocks_o20_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
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
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, rocks_o20_ROTATION[0], 
                                                rocks_o20_ROTATION[1], 
                                                rocks_o20_ROTATION[2], 
                                                rocks_o20_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, rocks_o20_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 4155, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(rocks_o20_isActive == false && rocks_o20_isLoaded == true)                                         
    {                                                                                       
        if(rocks_o20_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &rocks_o20_COLORMAP);                                              
            rocks_o20_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        rocks_o20_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
