<script lang="ts">
	import Router from "svelte-spa-router";
	import Home from "./Home.svelte";
	import Chat from "./Chat.svelte";
	import Canvas from "./Canvas.svelte";

	const routes = {
		'/': Home,
		'/chat': Chat,
		'/canvas': Canvas
	};
</script>

<main>
	<a href="/">home</a>
	<a href="#/chat">chat</a>
	<a href="#/canvas">canvas</a>

	<Router {routes}/>
</main>

<style>

</style>