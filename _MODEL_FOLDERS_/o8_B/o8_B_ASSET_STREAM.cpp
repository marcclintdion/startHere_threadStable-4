#ifdef WIN32 
void load_o8_B_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o8_B = FreeImage_GetFileType(o8_B_FilePath, 0);                       
    dib_o8_B   = FreeImage_Load(fifmt_o8_B, o8_B_FilePath, 0);                    
    temp_o8_B  = dib_o8_B;                                                      
    dib_o8_B   = FreeImage_ConvertTo32Bits(temp_o8_B);                          
    FreeImage_Unload(temp_o8_B);                                            

    if( dib_o8_B != NULL )                                                    
    {                                                                       
        pixels_o8_B = (BYTE*)FreeImage_GetBits(dib_o8_B);                       
    }                                                                     

    o8_B_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o8_B_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o8_B != NULL )                                                    
    {                                                                       
        free(pixels_o8_B);                                                    
        FreeImage_Unload(dib_o8_B);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
