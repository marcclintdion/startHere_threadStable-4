#ifdef WIN32 
void load_o17_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o17 = FreeImage_GetFileType(o17_FilePath, 0);                       
    dib_o17   = FreeImage_Load(fifmt_o17, o17_FilePath, 0);                    
    temp_o17  = dib_o17;                                                      
    dib_o17   = FreeImage_ConvertTo32Bits(temp_o17);                          
    FreeImage_Unload(temp_o17);                                            

    if( dib_o17 != NULL )                                                    
    {                                                                       
        pixels_o17 = (BYTE*)FreeImage_GetBits(dib_o17);                       
    }                                                                     

    o17_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o17_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o17 != NULL )                                                    
    {                                                                       
        free(pixels_o17);                                                    
        FreeImage_Unload(dib_o17);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
