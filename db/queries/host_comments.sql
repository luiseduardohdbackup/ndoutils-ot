SELECT 
nagios_instances.instance_id
,nagios_instances.instance_name
,nagios_comments.object_id
,obj1.name1 AS host_name
,nagios_comments.*
FROM `nagios_comments`
LEFT JOIN nagios_objects as obj1 ON nagios_comments.object_id=obj1.object_id
LEFT JOIN nagios_instances ON nagios_comments.instance_id=nagios_instances.instance_id
WHERE obj1.objecttype_id='1'
ORDER BY entry_time DESC, entry_time_usec DESC, comment_id DESC

