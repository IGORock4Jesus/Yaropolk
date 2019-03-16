namespace Yaropolk
{
	internal class Component
	{
		public GameObject GameObject { get; private set; }

		internal void Initialize(GameObject gameObject)
		{
			this.GameObject = gameObject;
			OnInitialize();
		}

		protected virtual void OnInitialize() { }
	}
}