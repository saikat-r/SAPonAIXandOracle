select segment_name,owner from dba_segments where bytes = (select max(bytes) from dba_segments);
