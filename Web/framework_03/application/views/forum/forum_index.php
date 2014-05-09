<h1><?php url(lang('title_forum'), 'forum/forum_index'); ?></h1>
<?php if (get_level() == 10): ?>
<div class="form">
<form method="post" action="<?php echo site_url('forum/forum_create'); ?>">
		<div class="field">
			<input type="text" placeholder="<?php echo lang('forum_title'); ?>" name="title" class="full" value="">
		</div>
		<div class="field">
			<input class="full" placeholder="<?php echo lang('forum_description'); ?>" type="text" name="description">
		</div>
		<div class="field">
			<input type="submit" value="<?php echo lang('btn_create'); ?>" class="btn" name="submit">
		</div>
	</form>
</div>
<br>
<?php
endif;
echo "<ul>";
foreach ($forums as $forum)
{
	echo "<li class='forum_cat'><a href='".site_url('forum/forum_category/'.$forum->id)."'>";
	echo $forum->title;
	echo " - ";
	echo $forum->description;
	echo "</a>";
	if (get_level() == 10)
	{
		echo "   -   ";
		echo url_icon("", "remove", "forum/forum_delete_category/".$forum->id);
	}
	echo "</li>";
}
echo "</ul>";
?>
