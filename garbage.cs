List<int> ids;

foreach(var id in ids){

    //Update SenderList for current senderCode
    var linkJobSenderListUpdateCommand = 
                "update LinkJobs " + 
                "set SenderList = REPLACE(SenderList, @senderCode + ';', '') " + 
                "where id = @id";
    
    //update SenderList for empty semidcolon for sender
    var linkJobSenderListEmptySemicolon = 
                "update LinkJobs " + 
                "set SenderList = REPLACE(SenderList, ';;', ';') " + 
                "where id = @id";

    //calculate number of senders in SenderList
    var senderList = "select senderList from LinkJobs where id = @id";

    var senderCount = senderList.Split(';');

	senderCount = senderCount.Where((x => !string.IsNullOrWhiteSpace(x))).ToArray();

    if(senderCount.Count() <= 1){
        var linkJobGenerationdisabledUpdateCommand = 
                "update LinkJobs" +
                "set GenerationDisables = 1" +
                "where id = @id";
    }
} 