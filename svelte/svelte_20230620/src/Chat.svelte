<script lang="ts">
    let inputValue: string = "";
    const buttonClickEvent = () => {
        const newChat = document.createElement("div") as HTMLDivElement;
        newChat.className = "newChat";
        newChat.innerText = inputValue;

        document.getElementById("conversations").appendChild(newChat);
        inputValue = "";
    }
</script>

<div id="conversations">
    <div class="newChat">test</div>
</div>
<input type="text" bind:value={inputValue} />
<button on:click={buttonClickEvent}>Enter</button>

<style>
    #conversations {
        display: flex;
        flex-direction: column;
        border: 1px solid black;
        width: 300px;
        padding: 10px;
        margin: 10px;
        border-radius: 10px;        
    }

    :global(.newChat) {
        padding: 10px;
        overflow: visible;
        width: 250px;
        color: blue;
        background-color: antiquewhite;        
    }

</style>